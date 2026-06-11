#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

int main(void){
    int a,b,H,M;
    cin >> a >> b >> H >> M;
    
    double th = double (H*60+M)/720 * 2*PI;
    double tm = double (M)/60 * 2*PI;
    
    double xh = a*cos(th), yh = a*sin(th);
    double xm = b*cos(tm), ym = b*sin(tm);
    
    double dx = xh - xm, dy = yh - ym;
    double ans = sqrt(dx*dx + dy*dy);
    printf("%.12f",ans);
    return 0;
}