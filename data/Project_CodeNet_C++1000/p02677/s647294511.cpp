#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define PI 3.141592653589793238

void solve()
{
    long double a, b, h, m;
    cin >> a >> b >> h >> m;

    m += h*60;
    long double s = m*5.5;

    while(s-360>0)
    {
        s -= 360;
    }
    s *= PI/180.0;
    long double ans = sqrt(a*a+b*b-2*a*b*cos(min(s, 2*PI-s)));

    cout << fixed << showpoint;
    cout << setprecision(20);
    cout << ans << endl;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll t;
    solve();
    return 0;
}
