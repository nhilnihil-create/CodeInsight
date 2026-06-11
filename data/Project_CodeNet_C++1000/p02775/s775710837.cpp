#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using lli = long long int;
lli dp[1000005][2] = {};
// iまで見て1つ払ってる
void solve(string N)
{
  int n = N.size();
  dp[n - 1][0] = N[n - 1] - '0';
  dp[n - 1][1] = 10 - (N[n - 1] - '0');

  for (int i = n - 2; i >= 0; i--)
  {
    int c = N[i] - '0';
    dp[i][0] = min(dp[i + 1][0] + c, dp[i + 1][1] + c + 1);
    dp[i][1] = min(dp[i + 1][0] + 10 - c, dp[i + 1][1] + 9 - c);
  }
  cout << min(dp[0][0], 1 + dp[0][1]) << endl;
}

int main()
{
  string S;
  cin >> S;
  solve(S);
  return 0;
}
