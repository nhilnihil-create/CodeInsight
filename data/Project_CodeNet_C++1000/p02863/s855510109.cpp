#include<bits/stdc++.h>
using namespace std;

using ll = int_fast64_t;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define repr(i,n) for(int i{n};i-->0;)

signed main(){

  int n,t;
  cin>>n>>t;
  vector<int> a(n),b(n);
  rep(i,n)cin>>a[i]>>b[i];

  auto solve = [](auto const& a,auto const& b,int n,int t){
    vector dp(n+1,vector(6010,0));
    rep(i,n)rep(j,min(t+1,3001)){
      dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
      dp[i+1][j+a[i]] = max(dp[i+1][j+a[i]],dp[i][j]+b[i]);
    }
    return dp;
  };
  auto rev = [](auto vec){
    reverse(begin(vec),end(vec));
    return vec;
  };

  auto dp1 = solve(a,b,n,t);
  auto dp2 = solve(rev(a),rev(b),n,t);

  auto merge_dp = [&](int i){
    auto& previous = dp1[i];
    auto& following = dp2[n-i-1];
    int res = 0;
    rep(k,t){
      res = max(res,previous[k]+following[t-k-1]);
    }
    return res+b[i];
  };

  int ans = 0;
  rep(i,n){
    ans = max(ans,merge_dp(i));
  }
  cout<<(ans)<<endl;

  //cout<<endl;rep(i,n+1){rep(j,t+1)cout<<dp1[i][j]<<" ";cout<<endl;}
  //cout<<endl;rep(i,n+1){rep(j,t+1)cout<<dp2[i][j]<<" ";cout<<endl;}

}
