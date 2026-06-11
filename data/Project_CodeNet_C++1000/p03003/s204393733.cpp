#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 1000000007;
int64_t dp[2010][2010]; // Sのi番目, Tのj番目までの共通部分列ペアの個数

void init()
{
  for (int i = 0; i < 2010; i++)
  {
    dp[0][i] = dp[i][0] = 1;
  }
}

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> S(N), T(M);
  for (int i = 0; i < N; i++)
  {
    cin >> S.at(i);
  }
  for (int i = 0; i < M; i++)
  {
    cin >> T.at(i);
  }
  init();
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= M; j++)
    {
      if (S[i - 1] == T[j - 1])
      {
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
      }
      else
      {
        dp[i][j] = ((dp[i - 1][j] + dp[i][j - 1]) % MOD - dp[i - 1][j - 1] + MOD) % MOD;
      }
    }
  }
  cout << dp[N][M] << endl;
}