#include <bits/stdc++.h>
using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vt<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(rall(a));

    vt<vt<ll>> dp(n + 1, vt<ll>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int l = 0; l <= i + 1; l++) {
            int r = i - l + 1;
            if (l) dp[l][r] = max(
                    dp[l][r],
                    dp[l - 1][r] + (ll)a[i].fi * abs(a[i].se - l + 1)
                );
            if (r) dp[l][r] = max(
                    dp[l][r],
                    dp[l][r - 1] + (ll)a[i].fi * abs(a[i].se - n + r)
                );
        }
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, dp[n - i][i]);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}
