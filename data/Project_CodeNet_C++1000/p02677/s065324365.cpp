#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;
 
int main(){
    double a,b,h,m;
    cin >> a >> b >> h >> m;
    double ha = (h*30 + 30*m/60)*2*M_PI/360;
    double ma = m*6*2*M_PI/360;
    double angle = max(abs(ha-ma),2*M_PI-abs(ha-ma));
    double ans = sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(angle));
    cout << fixed << setprecision(20) << ans << endl;
}