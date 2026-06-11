#include <bits/stdc++.h>
using namespace std;
#define pi 3.141592653589793

int main() {
    double A, B, H, M;
    cin >> A >> B >> H >> M;
    cout <<  fixed << setprecision(20) << (double)sqrt((double)(A*cos(0.5*pi - 30*(H + M/60)*pi/180) - B*cos(0.5*pi - 6*M*pi/180))*(A*cos(0.5*pi - 30*(H + M/60)*pi/180) - B*cos(0.5*pi - 6*M*pi/180)) + (A*sin(0.5*pi - 30*(H + M/60)*pi/180) - B*sin(0.5*pi - 6*M*pi/180))*(A*sin(0.5*pi - 30*(H + M/60)*pi/180) - B*sin(0.5*pi - 6*M*pi/180))) << endl;
}
