#include <bits/stdc++.h>
using namespace std;

int main() {
    long double A,B,H,M;
    cin >> A >> B >> H >> M;
    long double PI=3.1415926535;
    long double theta=(30.0*(H+M/60.0) - 6.0*M)/180.0*PI;
    cout<< setprecision(10) << sqrtl((A*A+B*B)-(2.0*A*B*cosl(theta))) << endl;

    }
    