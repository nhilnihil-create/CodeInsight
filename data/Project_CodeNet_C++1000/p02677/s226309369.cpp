#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,h,m;
    double pi = M_PI;
    cin >> a >> b >> h >> m;
    double theta_t = 2 * pi * (60 * h + m)/720;
    double theta_m = 2 * pi * m / 60;
    double tx,ty,mx,my;
    tx = a * cos(theta_t);
    ty = a * sin(theta_t);
    mx = b * cos(theta_m);
    my = b * sin(theta_m);
    //cout << tx <<" " <<  ty <<" "<< mx <<" "<< my << endl;
    double d2 = (tx - mx)*(tx-mx) + (ty - my) * (ty - my);
    double d = sqrt(d2);
    printf("%21.20lf",d);
}