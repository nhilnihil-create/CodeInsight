#include <bits/stdc++.h>
using namespace std;

#define MAX 2010

const int MOD = 1e9 + 7;

int dp[MAX][MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;

  vector<int> v(n + 1), w(m + 1);

  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    dp[i][0] = 1;
  }
  for (int i = 1; i <= m; i++) {
    cin >> w[i];
    dp[0][i] = 1;
  }

  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
      if (v[i] != w[j])
        dp[i][j] = (MOD + dp[i][j] - dp[i - 1][j - 1]) % MOD;
    }
  }

  cout << dp[n][m] << endl;

  return 0;
}
