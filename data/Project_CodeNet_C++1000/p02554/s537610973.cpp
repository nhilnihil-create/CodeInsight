#include <bits/stdc++.h>
using namespace std;

#define int long long

int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(4));

    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j == 0) {
                dp[i][1] = (dp[i][1] + dp[i - 1][0] + dp[i - 1][1]) % MOD;
                dp[i][3] = (dp[i][3] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
            } else if (j == 9) {
                dp[i][2] = (dp[i][2] + dp[i - 1][0] + dp[i - 1][2]) % MOD;
                dp[i][3] = (dp[i][3] + dp[i - 1][1] + dp[i - 1][3]) % MOD;
            } else {
                for (int k = 0; k < 4; ++k) {
                    dp[i][k] = (dp[i][k] + dp[i - 1][k]) % MOD;
                }
            }
        }
    }

    cout << dp[n][3];
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}