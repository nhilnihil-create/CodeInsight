#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    int a[n + 1];
    rep(i, n + 1) {
        cin >> a[i];
    }
    ll sum[n + 2] = {};
    for (int i = n; i >= 0; i--) {
        sum[i] = sum[i + 1] + a[i];
    }
    ll ans = 0, now = 1;
    rep(i, n + 1) {
        ans += min(now, sum[i]);
        now -= a[i];
        if(now < 0){
            cout << -1 << endl;
            return 0;
        }
        now = min(now * 2, LINF);
    }
    cout << ans << endl;
    return 0;
}