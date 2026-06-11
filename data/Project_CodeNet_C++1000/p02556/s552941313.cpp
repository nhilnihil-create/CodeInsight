#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    ll minx, miny, maxx, maxy;
    minx = miny = 3e9;
    maxx = maxy = -minx;
    // printf("%lld %lld %lld %lld\n", minx, miny, maxx, maxy);
    rep(i, n)
    {
        ll x, y;
        cin >> x >> y;
        minx = min(minx, x + y);
        miny = min(miny, x - y);
        maxx = max(maxx, x + y);
        maxy = max(maxy, x - y);
    }
    ll ans = max(maxx - minx, maxy - miny);
    cout << ans << endl;
    return 0;
}