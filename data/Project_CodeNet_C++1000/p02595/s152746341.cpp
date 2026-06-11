#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct point
{
    ll x, y;
};
point a[200009];
ll n;
double d;
ll ans;
void inp()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
}
double distan(point a)
{
    double k = ((a.x*a.x) + (a.y*a.y))*1.0;
    return (sqrt(k));
}
void process()
{
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (distan(a[i]) <= d) ans++;
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.inp","r", stdin);
    inp();
    process();
    return 0;
}
