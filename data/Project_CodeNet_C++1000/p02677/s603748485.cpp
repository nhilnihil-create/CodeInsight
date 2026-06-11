#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;

const double PI = acos(-1);

int main()
{
    int a,b, h, m; 
    cin >> a >> b >> h >> m;

    double ta,tb;
    ta = double(60*h + m)/720 * 2 * PI;
    tb = double(m)/60 * 2 * PI;

    double ax,ay,bx,by;
    ax = a * cos(ta);
    ay = a * sin(ta);
    bx = b * cos(tb);
    by = b * sin(tb);
    double dx,dy;
    dx = ax - bx;
    dy = ay - by;
    double ans;
    ans = sqrt(dx*dx + dy*dy);

    printf("%.10f\n", ans);
    // cout << fixed << setprecision(20) << ans << endl;

}

