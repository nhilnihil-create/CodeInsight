#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n, s;
    int64_t mod = 998244353;
    cin >> n >> s;
    vector < int > a(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vector < vector < int64_t > > dp(n + 1, vector < int64_t > (s + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= s; ++j) {
            (dp[i][j] += 2 * dp[i - 1][j]) %= mod;
            if (j + a[i] <= s)
                (dp[i][j + a[i]] += dp[i - 1][j]) %= mod;
        }
    }
    cout << dp[n][s] << '\n';
}
