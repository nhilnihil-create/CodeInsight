#include <bits/stdc++.h>
using namespace std;

int main(){
    double A,B,H,M;
    cin >> A >> B >> H >> M;
    double argh=0,argm=0;
    double pi = 3.14159265358979;
    argm=2*pi*M/60;
    //cout << argm << endl;
    argh=2*pi*H/12+pi/6*M/60;
    //cout << argh << endl;
    double arg = abs(argm-argh);
    double ans = A*A + B*B - 2*A*B*cos(arg);
    printf("%.11lf",sqrt(ans));
    return 0;
}