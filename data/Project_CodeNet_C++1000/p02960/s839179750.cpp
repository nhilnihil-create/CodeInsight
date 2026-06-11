#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  ll mod = 1000000007;
  string s;
  cin >> s;
  vector<vector<ll>> dp(s.size(), vector<ll>(13, 0));
  if (s[s.size()-1] == '?')
    rep(i, 10)
      dp[s.size()-1][i] = 1;
  else
    dp[s.size()-1][(s[s.size()-1]-'0')%13] = 1;
  int d = 1;
  for (int i = s.size() - 2; i >= 0; i--)
  {
    d = d * 10 % 13;
    if (s[i] == '?')
      rep(j, 10)
      {
        int a = d * j % 13;
        rep(k, 13)
          dp[i][(k+a)%13] = (dp[i][(k+a)%13] + dp[i+1][k]) % mod;
      }
    else
    {
      int a = d * (s[i] - '0') % 13;
      rep(j, 13)
        dp[i][(j+a)%13] = dp[i+1][j];
    }
  }
  cout << dp[0][5] << endl;
  return 0;
}