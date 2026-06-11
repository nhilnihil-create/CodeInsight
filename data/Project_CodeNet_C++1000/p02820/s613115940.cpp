#include<bits/stdc++.h>
using namespace std;

using ll = int_fast64_t;
#define rep(i,n) for(int i=0;i<(n);++i)

signed main(){

  ll n,k,r,s,p;
  cin>>n>>k>>r>>s>>p;
  string t;
  cin>>t;

  vector<string> x(k);
  rep(i,n){
    x[i%k] += t[i];
  }

  auto solve = [&](string const& str)->ll{
    int m = size(str);
    vector dp(3,vector(m+1,0ll));
    rep(i,m){
      dp[0][i+1]=max(dp[1][i],dp[2][i]);
      dp[1][i+1]=max(dp[0][i],dp[2][i]);
      dp[2][i+1]=max(dp[0][i],dp[1][i]);
      if(str[i]=='r')dp[0][i+1] += p;
      if(str[i]=='s')dp[1][i+1] += r;
      if(str[i]=='p')dp[2][i+1] += s;
    }
    return max({dp[0][m],dp[1][m],dp[2][m]});
  };

  ll ans = 0;
  rep(i,k)ans+=solve(x[i]);

  cout<<(ans)<<endl;

}