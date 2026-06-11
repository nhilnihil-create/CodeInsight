#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int w, h, x, y;
    cin >> w >> h >> x >> y;
    double ans1 = (double) w * h / 2;
    int ans2 = 0;
    if(2 * x == w && 2 * y == h) ans2 = 1;
    cout << setprecision(15) << ans1 << " " << ans2 << endl;
    return 0;
}
