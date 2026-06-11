#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int n, m; cin >> n >> m;
    vector<int> s(n), t(m);
    REP(i, 0, n) cin >> s[i];
    REP(i, 0, m) cin >> t[i];

    ll dp[n + 1][m + 1] = {};
    REP(i, 0, n + 1) dp[i][0] = 1;
    REP(i, 0, m + 1) dp[0][i] = 1;
    REP(i, 0, n) {
        REP(j, 0, m) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
            }
            dp[i + 1][j + 1] = ((dp[i + 1][j + 1] + dp[i + 1][j]) % MOD + dp[i][j + 1]) % MOD;
            dp[i + 1][j + 1] = (MOD + dp[i + 1][j + 1] - dp[i][j]) % MOD;

        }
    }
    cout << dp[n][m] << endl;
    return 0;
}