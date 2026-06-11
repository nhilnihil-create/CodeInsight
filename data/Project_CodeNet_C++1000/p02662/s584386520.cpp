#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using field = vector<vector<ll>>;

int main() {
  int n,s;
  cin >> n >> s;
  ll mod = 998244353;
  field dp(n+1,vector<ll>(s+1,0));
  dp[0][0] = 1;
  rep(i,0,n) {
    ll a;
    cin >> a;
    rep(j,0,s+1) {
      dp[i+1][j] += dp[i][j]*2;
      dp[i+1][j] %= mod;
      if (j+a <= s) {
        dp[i+1][j+a] += dp[i][j];
        dp[i+1][j+a] %= mod;
      }
    }
  }
  cout << dp[n][s] << endl;
  return 0;
}
