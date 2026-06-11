#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 1000000007;
const int64_t MAXN = 100010;
int64_t dp[MAXN][2]; // i桁目, isLess?

int main()
{
  string L;
  cin >> L;
  dp[0][0] = 1;
  int64_t n = L.size();
  for (int i = 0; i < n; i++)
  { // a + b = 0
    if (L[i] == '0')
    {
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] = dp[i][1];
    }
    else
    {
      dp[i + 1][1] = (dp[i][0] + dp[i][1]) % MOD;
    }
    if (L[i] == '0')
    {
      (dp[i + 1][1] += dp[i][1] * 2 % MOD) %= MOD;
    }
    else
    {
      (dp[i + 1][0] += dp[i][0] * 2 % MOD) %= MOD;
      (dp[i + 1][1] += dp[i][1] * 2 % MOD) %= MOD;
    }
  }
  int64_t ans = (dp[n][0] + dp[n][1]) % MOD;
  cout << ans << endl;
}
