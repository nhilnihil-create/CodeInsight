#include <bits/stdc++.h>
using namespace std;
int dp[5010][5010];

int main()
{
  int N, ans = 0;
  string S;
  cin >> N >> S;
  for (int i = N - 1; i >= 0; i--)
  {
    for (int j = N - 1; j >= 0; j--)
    {
      if (S[i] == S[j])
      {
        dp[i][j] = dp[i + 1][j + 1] + 1;
      }
    }
  }
  for (int i = 0; i < N - 1; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      ans = max(ans, min(dp[i][j], j - i));
    }
  }
  cout << ans << endl;
}