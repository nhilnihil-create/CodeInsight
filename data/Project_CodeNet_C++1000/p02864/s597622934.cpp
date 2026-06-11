#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    int m = n - k;
    vector<ll> h(n + 1, 0);
    rep(i, n) cin >> h[i + 1];

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            ll now = 1e18;
            for (int x = 0; x < i; x++) {
                now = min(now, dp[x][j] + max(0LL, h[i] - h[x]));
            }
            dp[i][j + 1] = now;
        }
    }
    ll ans = 1e18;
    rep(i, n + 1) {
        ans = min(ans, dp[i][m]);
    }
    cout << ans << endl;
}