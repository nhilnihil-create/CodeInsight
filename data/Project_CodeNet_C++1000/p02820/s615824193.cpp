#include<bits/stdc++.h>
using namespace std;

using ll = int_fast64_t;
#define rep(i,n) for(int i=0;i<(n);++i)

signed main(){

  int N,K,R,S,P;
  string T;
  cin>>N>>K>>R>>S>>P>>T;

  auto solve = [&](string const& s){
    int n = size(s);
    vector dp(n+1,vector(3,0));
    rep(i,n){
      if(s[i]=='r')dp[i+1][0] = max(dp[i][1],dp[i][2])+P;
      if(s[i]=='s')dp[i+1][1] = max(dp[i][0],dp[i][2])+R;
      if(s[i]=='p')dp[i+1][2] = max(dp[i][0],dp[i][1])+S;
      rep(j,3)rep(k,3)if(j!=k)dp[i+1][j] = max(dp[i+1][j],dp[i][k]);
    }
    return max({dp[n][0],dp[n][1],dp[n][2]});
  };

  vector<string> s(K);
  rep(i,N)s[i%K]+=T[i];

  ll ans = 0;
  rep(i,K)ans += solve(s[i]);
  cout<<(ans)<<endl;

}