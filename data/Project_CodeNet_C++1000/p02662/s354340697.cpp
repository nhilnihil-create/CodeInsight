#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 998244353;
int64_t dp[3010][3010]; // i番目までで合計がjとなる個数

int main()
{
  int64_t N, S;
  cin >> N >> S;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  dp[0][0] = 1;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j <= S; j++)
    {
      if (dp[i][j] == 0)
        continue;
      (dp[i + 1][j] += (2 * dp[i][j]) % MOD) %= MOD;
      if (j + A.at(i) <= S)
      {
        (dp[i + 1][j + A.at(i)] += dp[i][j]) %= MOD;
      }
    }
  }
  cout << dp[N][S] << endl;
}