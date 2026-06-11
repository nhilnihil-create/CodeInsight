#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> keys(m);
  rep(i, m)
  {
    int b;
    cin >> keys[i].first >> b;
    keys[i].second = 0;
    rep(j, b)
    {
      int c;
      cin >> c;
      keys[i].second |= 1 << (c - 1);
    }
  }
  vector<vector<int>> dp(m + 1, vector<int>(1<<n, INT_MAX));
  dp[0][0] = 0;
  rep(i, m)
    rep(j, 1<<n)
    {
      if (dp[i][j] == INT_MAX)
        continue;
      dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
      dp[i+1][j|keys[i].second] = min(dp[i+1][j|keys[i].second], dp[i][j] + keys[i].first);
    }
  if (dp[m-1][(1<<n)-1] == INT_MAX)
    puts("-1");
  else
    cout << dp[m][(1<<n)-1] << endl;
  return 0;
}