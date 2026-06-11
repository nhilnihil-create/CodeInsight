//AC
#include<bits/stdc++.h>
using namespace std;

int A, B, H, M;

void rotate(double& x, double& y, double theta){
    double x_buf = x, y_buf = y;
    x = cos(theta)*x_buf - sin(theta)*y_buf;
    y = sin(theta)*x_buf + cos(theta)*y_buf;
}

int main(){
    cin >> A >> B >> H >> M;
    pair<double,double> ph = make_pair(0,A), pm = make_pair(0,B);
    double vh = 2*M_PI/12/60, vm = 2*M_PI/60;
    double theta_h, theta_m;
    theta_m = vm * M;
    theta_h = vh * (60*H + M);
    rotate(ph.first, ph.second, theta_h);
    rotate(pm.first, pm.second, theta_m);
    cout << setprecision(20) << sqrt(pow(ph.first-pm.first,2)+pow(ph.second-pm.second,2)) << endl;
    return 0;
}