#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> s(n);
  vector<int> t(m);
  REP(i, n) { cin >> s[i]; }
  REP(i, m) { cin >> t[i]; }

  ll dp[n + 1][m + 1] = {};
  REP(i, n + 1) { dp[i][0] = 1; }
  REP(i, m + 1) { dp[0][i] = 1; }
  REP(i, n) {
    REP(j, m) {
      if (s[i] == t[j]) {

        dp[i + 1][j + 1] = (dp[i + 1][j] + dp[i][j + 1]) % MOD;
      } else {
        dp[i + 1][j + 1] =
            (((dp[i + 1][j] + dp[i][j + 1]) % MOD) - dp[i][j] + MOD) % MOD;
      }
    }
  }
  cout << dp[n][m] << endl;
}
