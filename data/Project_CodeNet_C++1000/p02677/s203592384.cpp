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
    double ans;
    pair<double,double> ph = make_pair(0,A), pm = make_pair(0,B);
    double vh = 2*M_PI/12/60, vm = 2*M_PI/60; //角速度(毎分)
    double x_buf, ybuf;
    double theta_h, theta_m;
    theta_m = vm * M;
    theta_h = vh * (60*H + M);
    rotate(ph.first, ph.second, theta_h);
    rotate(pm.first, pm.second, theta_m);
    ans = sqrt(pow(ph.first-pm.first,2)+pow(ph.second-pm.second,2));
    cout << setprecision(20) << ans << endl;
    return 0;
}

/*
時針の位置
それぞれの針の角速度は？(単位を分速に合わせる)
2Pi/12/60
分針の位置
2Pi/60
*/