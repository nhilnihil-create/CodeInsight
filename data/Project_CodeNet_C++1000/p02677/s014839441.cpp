#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main()
{
    int a,b,h,m;
    cin >> a >> b >> h >> m;
    double hx,hy,mx,my;
    double htheta = M_PI*(h + (double)m/60)* 30/180;
    double mtheta = M_PI*(h*60 + m)*6/180;
    hx = a*sin(htheta);
    hy = a*cos(htheta);
    mx = b*sin(mtheta);
    my = b*cos(mtheta);
    double ans = sqrt(pow(hx-mx,2) + pow(hy-my,2));
    cout << fixed << setprecision(10) << ans << endl;
return 0;
}