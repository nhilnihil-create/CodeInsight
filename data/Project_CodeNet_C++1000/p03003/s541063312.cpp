#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;
const int MAX_NM = 2000;

ll dp[MAX_NM + 5][MAX_NM + 5];
ll sum[MAX_NM + 5][MAX_NM + 5];

int main() {
    int n, m;
    cin >> n >> m;
    int s[n], t[m];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < m; i++) cin >> t[i];
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = sum[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = 0;
            }
            dp[i + 1][j + 1] %= MOD;
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + dp[i + 1][j + 1];
            sum[i + 1][j + 1] %= MOD;
            while (sum[i + 1][j + 1] < 0) sum[i + 1][j + 1] += MOD;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += dp[i + 1][j + 1];
            ans %= MOD;
        }
    }
    cout << ans + 1 << endl;
}