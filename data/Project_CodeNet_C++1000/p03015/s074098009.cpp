#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const int INF=1001001001;
const int mod=1000000007;


int main() {
  string s;cin>>s;
  int n=s.size();
  int dp[n+5][2];
  rep(i,n+5)rep(j,2)dp[i][j]=0;
  dp[0][0]=1;//同じ
  dp[0][1]=0;//未満
  rep(i,n) {
    { // a+b = 0
      if (s[i] == '0') {
        dp[i+1][0] = dp[i][0];
        dp[i+1][1] = dp[i][1];
      } else {
        dp[i+1][1] = (dp[i][0] + dp[i][1]) % mod;
      }
    }
    { // a+b = 1
      if (s[i] == '0') {
        (dp[i+1][1] += dp[i][1]*2 % mod) %= mod;
      } else {
        (dp[i+1][0] += dp[i][0]*2 % mod) %= mod;
        (dp[i+1][1] += dp[i][1]*2 % mod) %= mod;
      }
    }
  }
  int ans=dp[n][0]%mod+dp[n][1]%mod;
  ans=ans%mod;
  
  cout<<ans;

  }
