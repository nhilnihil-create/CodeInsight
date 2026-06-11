#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n, t;
  cin >> n >> t;
  vector<pair<int, int>> f(n);
  rep(i, n)
  {
    int a, b;
    cin >> a >> b;
    f[i].first = a;
    f[i].second = b;
  }
  sort(f.begin(), f.end());
  vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
  rep(i, n)
  {
    dp[i+1][t] = max(dp[i][t], dp[i][t-1] + f[i].second);
    for (int j = 1; j < t; j++)
    {
      dp[i+1][j] = max(dp[i][j], dp[i+1][j-1]);
      if (f[i].first <= j)
        dp[i+1][j] = max(dp[i+1][j], dp[i][j-f[i].first] + f[i].second);
    }
  }
  cout << dp[n][t] << endl;
  return 0;
}