#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    for (int i = 0; i < n; i++)cin >> s[i];
    vector<int> t(m);
    for (int i = 0; i < m; i++)cin >> t[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
    for (int i = 0; i <= n; i++)dp[i][0] = 1;
    for (int j = 0; j <= m; j++)dp[0][j] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
            if (s[i] != t[j])dp[i + 1][j + 1] -= dp[i][j];

            dp[i + 1][j + 1] += MOD * 10, dp[i + 1][j + 1] %= MOD;
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}