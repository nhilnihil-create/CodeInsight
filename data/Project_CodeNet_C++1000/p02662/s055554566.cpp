#include <iostream>

using namespace std;
const int MAXN = 3005;
const int MOD = 998244353;
int n, s, dp[MAXN][MAXN];

int main() {
    cin >> n >> s;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        for (int j = 0; j <= s; ++j) {
            dp[i][j] = 2 * dp[i - 1][j] % MOD;
            if (j >= t) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - t]) % MOD;
            }
        }
    }
    cout << dp[n][s] << endl;
    return 0;
}