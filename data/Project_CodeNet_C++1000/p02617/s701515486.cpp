#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    ll ans = 0;
    for (int v = 1; v <= n; v++) {
        ans += (ll)v * (n + 1 - v);
    }
    int u, v;
    rep(i, n - 1) {
        cin >> u >> v;
        if (u > v) swap(u, v);
        ans -= (ll)u * (n + 1 - v);
    }
    cout << ans << endl;
    return 0;
}