#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;

ll MOD = 1000000007;

int main()
{
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
  
  dp[0][0] = 1;
  rep(i, n) rep(j, 2) rep(d, 3)
  {
    int c = s[i]-'0';
    int ni = i+1, nj = j;
    if(j == 0 && d && c == 0) break;
    if(j == 0 && d == 0 && c) nj++;
    dp[ni][nj] = (dp[ni][nj] + dp[i][j]) % MOD;
  }
  cout << (dp[n][0] + dp[n][1]) % MOD << endl;

  return 0;
}