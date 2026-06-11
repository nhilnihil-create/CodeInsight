// 7/1 解き直し → 6/30
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1000000007;

// 中点それ自体である時はできない。

int main() {
    double W, H, x, y;
    cin >> W >> H >> x >> y;

    double ans = W * H / 2.0;
    cout << fixed << setprecision(15);
    cout << ans << endl;

    if (2 * x == W && 2 * y == H) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}