#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using namespace std;

int main()
{
    ll w, h, x, y;
    cin >> w >> h >> x >> y;
    if (x == 0 && y == 0 || x == 0 && y == h || x == w && y == h || x == w && y == 0) {
        long double ans = w * h / 2.0;
        cout << ans << " ";
        cout << 0 << endl;
        return 0;
    }
    if (x == 0 || y == 0 || x == w || y == h) {
        long double ans = w * h / 2.0;
        cout << ans << " ";
        cout << 0 << endl;
        return 0;
    }
    ll b = min(x * h, (w-x) * h);
    ll d = min(y * w, (h-y) * w);
    long double res = w * h / 2.0;
    cout << res << " ";
    if (b == d) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}
