#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,sse")
using namespace std;

const int MOD = 1000000007;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> b(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + MOD) % MOD;
                if (a[i] == b[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
            }
        }
    }
    cout << dp[n][m] << endl;

    fflush(stdout);
    return 0;
}
