#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, t;
    cin >> n >> t;
    vt<pii> a(n);
    for (pii &i : a) cin >> i.fi >> i.se;
    sort(all(a));

    vt<int> dp(t);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = t - 1; j >= 0; j--) {
            int res = dp[j] + a[i].se;
            if (j + a[i].fi < t) {
                int &x = dp[j + a[i].fi];
                x = max(x, res);
            }
            ans = max(ans, res);
        }
    }

    cout << ans;
}
