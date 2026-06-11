#include<bits/stdc++.h>
using namespace std;

using ll = int_fast64_t;
#define rep(i,n) for(int i=0;i<(n);++i)

signed main(){

  int n;
  string s;
  cin>>n>>s;

  vector dp(n+1,vector(n+1,0));

  for(int i=0;i<n;++i){
    for(int j=i+1;j<n;++j){
      if(s[i]==s[j]){
        dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+1);
      }
      dp[i+1][j+1] = min(dp[i+1][j+1],j-i);
    }
  }

  int ans = 0;
  for(auto vec:dp)for(auto val:vec)ans=max(ans,val);
  cout<<(ans)<<endl;

}