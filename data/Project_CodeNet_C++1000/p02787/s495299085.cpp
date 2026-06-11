#include<bits/stdc++.h>
using namespace std;

using ll = int_fast64_t;
#define rep(i,n) for(int i=0;i<(n);++i)

signed main(){

  int h,n;
  cin>>h>>n;
  vector<int> a(n),b(n);
  rep(i,n)cin>>a[i]>>b[i];

  vector dp (h+1e5,1<<28);
  dp[0] = 0;
  rep(i,n)rep(j,h){
    auto& ai = a[i];
    auto& bi = b[i];
    dp[j+ai] = min(dp[j+ai],dp[j]+b[i]);
  }
  int ans = 1<<28;
  for(int i=h;i<h+1e5;++i)ans=min(ans,dp[i]);
  cout<<(ans)<<endl;

}