#include<bits/stdc++.h>
using namespace std;

using ll = int_fast64_t;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define repr(i,n) for(int i{n};i-->0;)

signed main(){

  int n,m;
  cin>>n>>m;
  vector<int> a(m),b(m),c(m);
  rep(i,m){
    cin>>a[i]>>b[i];
    rep(j,b[i]){
      int cij;
      cin>>cij;
      cij--;
      c[i] |= 1<<cij;
    }
  }

  vector dp(1<<12+1,1<<28);
  dp[0] = 0;
  rep(i,1<<12){
    rep(j,m){
      dp[i|c[j]] = min(dp[i|c[j]],dp[i]+a[j]);
    }
  }
  int ans = dp[(1<<n)-1];
  cout<<(ans>=1<<28?-1:ans)<<endl;


}