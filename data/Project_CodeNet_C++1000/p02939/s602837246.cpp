#include<bits/stdc++.h>
using namespace std;

using ll = int_fast64_t;
#define rep(i,n) for(int i=0;i<(n);++i)

signed main(){

  string s;
  cin>>s;

  auto solve = [](string const& s){
    int n  =size(s);
    vector dp(n+1,0);
    dp[1] = 1;
    for(int i=1;i<n;++i){
      if(s[i-1]==s[i])dp[i+1]=dp[i-1]+1;
      else dp[i+1]=dp[i]+1;
      if(i>=2)dp[i+1]=max(dp[i+1],dp[i-2]+2);
    }
    return dp[n];
  };

  int ans = solve(s);
  reverse(begin(s),end(s));
  ans = max(ans,solve(s));

  cout<<(ans)<<endl;

}