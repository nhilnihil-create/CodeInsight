#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(10);
    int n, k;
    cin >> n >> k;
    vector<ll> h(n + 1);
    rep(i, 1, n + 1) cin >> h[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(n - k + 1, 1e18));
    dp[0][0] = 0;

    rep(x, 1, n + 1) rep(y, 1, n - k + 1) {
        rep(i, 0, x) dp[x][y] =
            min(dp[x][y], dp[i][y - 1] + max(0LL, h[x] - h[i]));
    }

    ll ans = 1e18;
    rep(i, 0, n + 1) ans = min(ans, dp[i][n - k]);
    cout << ans << endl;

    return 0;
}