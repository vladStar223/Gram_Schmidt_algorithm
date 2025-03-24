#include <iostream>
#include <cmath>
#include <limits>
#include<sstream>
#include<vector>
using namespace std;


double scalar(vector<double>a, vector<double>b) {
    double s = 0;
    for (int i = 0; i < a.size(); i++) {
        s = s + (a[i] * b[i]);
    }
    return s;
}
vector<double> multiply_num_vector(vector<double>a, double x) {
    vector<double>b(a.size());
    for (int i = 0; i < a.size(); i++) {
        b[i] = a[i] * x;
    }
    return b;
}

vector<double> sum_vector(vector<double>a, vector<double>b) {
    vector<double>s(a.size());
    for (int i = 0; i < a.size(); i++) {
        s[i] = a[i] + b[i];
    }
    return s;
}
vector<double> minus_vector(vector<double>a, vector<double>b) {
    vector<double>s(a.size());
    for (int i = 0; i < a.size(); i++) {
        s[i] = a[i] - b[i];
    }
    return s;
}
vector<double> proj(vector<double>a,vector<double>e) {
    return multiply_num_vector(e,(scalar(a,e)/ scalar(e, e)));
}
int main() {

    setlocale(LC_ALL, "Russian");
    string data;
    string bw;
    int r = 2;
    int  n = 2;
    
    cout << "Hello user" << endl;
    n = 2;
    vector<double>test(r);
    vector<vector<double>>a(n, vector<double>(r));
    vector<vector<double>>e(n, vector<double>(r));
    for (int i = 0; i < n; i++) {
        cout << "Вводите базис вектороного пространства" << endl;
        cout << "В формате е1 е2 ... en" << endl;
        getline(cin, data);
        stringstream ss(data);
        for (int j = 0; j < r; j++) {
            ss >> bw;
            a[i][j] = stoi(bw);
       }

    }
    e[0] = a[0];
    vector<double> minus_proj(r);
    for (int i = 0; i < r; i++) {
        minus_proj[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        minus_proj = sum_vector(minus_proj, proj(a[i], e[i - 1]));
        e[i] = minus_vector(a[i], minus_proj);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            cout << e[i][j] << " ";
        }
        cout << "" << endl;
    }
   // b[0] = minus_vector(a[0], proj(a[0], a[1]));
   
    ///
    /*
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            cout << a[i][j] << " ";
        }
        cout << "" << endl;
    }
    */
    return 0;
}