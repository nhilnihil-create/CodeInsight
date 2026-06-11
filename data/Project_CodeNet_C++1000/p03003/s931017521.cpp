#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;
const int MAX_NM = 2000;

ll dp[MAX_NM + 5][MAX_NM + 5];

int main() {
    int n, m;
    cin >> n >> m;
    int s[n], t[m];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < m; i++) cin >> t[i];
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i > 0) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }
            if (j > 0) {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }
            if (i > 0 && j > 0 && s[i - 1] == t[j - 1]) {
                dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] %= MOD;
            }
            if (i > 0 && j > 0) {
                dp[i][j] -= dp[i - 1][j - 1];
                if (dp[i][j] < 0) dp[i][j] += MOD;
            }
        }
    }
    cout << dp[n][m] << endl;
}