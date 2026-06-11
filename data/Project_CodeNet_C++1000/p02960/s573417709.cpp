#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

ll MOD = 1000000007;

int main()
{
  string s;
  cin >> s;
  int n = s.size(), d = 13;
  vector<vector<ll>> dp(n+1, vector<ll>(d));
  //vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(d, vector<int>(2, 0)));
  
  dp[0][0] = 1;
  rep(i, n) rep(j, d)
  {
    if(s[i] != '?')
    {
      int c = s[i]-'0';
      int ni = i+1, nj = (j*10+c)%d;
      dp[ni][nj] = (dp[ni][nj]+dp[i][j])%MOD;
    }
    else
    {
      rep(k, 10)
      {
        int ni = i+1, nj = (j*10+k)%d;
        dp[ni][nj] = (dp[ni][nj]+dp[i][j])%MOD;
      }
    }
  }
  cout << dp[n][5] << endl;
  
  return 0;
}