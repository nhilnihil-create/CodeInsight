#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const ll mod = 1000000007;

int main()
{
  string s; cin >> s;
  int n = s.size();
  vector<vector<ll>> dp(n+1, vector<ll>(13));
  dp[0][0] = 1;

  rep(i, n) {
    rep(j, 13) {
      if (s[i] == '?') {
        rep(x, 10) {
          (dp[i+1][(j*10+x)%13] += dp[i][j]) %= mod;
        }
      } else {
        int x = s[i] - '0';
        (dp[i+1][(j*10+x)%13] += dp[i][j]) %= mod;
      }
    }
  }
  cout << dp[n][5] << endl;

  return 0;
}
