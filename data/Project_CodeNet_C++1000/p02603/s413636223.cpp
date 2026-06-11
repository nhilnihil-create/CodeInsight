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
    ll a[n];
    rep(i, n) {
        cin >> a[i];
    }
    ll ans = 1000;
    rep(i, n - 1) {
        if (a[i] >= a[i + 1]) continue;
        ll t = ans / a[i];
        ans -= a[i] * (ans / a[i]);
        ans += t * a[i + 1];
    }
    cout << ans << endl;
    return 0;
}