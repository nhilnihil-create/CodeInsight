#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
const Int MAX = 303;
const Int INF = 1e18;
Int dp[MAX][MAX][MAX];
signed main(){
  Int n,k;
  cin>>n>>k;
  vector<Int> hs(n);
  for(Int i=0;i<n;i++) cin>>hs[i];

  for(Int i=0;i<MAX;i++)
    for(Int j=0;j<MAX;j++)
      for(Int l=0;l<MAX;l++)
        dp[i][j][l]=INF;

  for(Int i=0;i<n;i++){
    dp[i][i][i]=hs[i];
    for(Int j=0;j+1<MAX;j++){
      for(Int l=0;l<i;l++){
        chmin(dp[i][j+0][i],dp[i-1][j][l]+max<Int>(hs[i]-hs[l],0));
        chmin(dp[i][j+1][l],dp[i-1][j][l]);
      }
    }
  }

  Int ans=(k==n?0:INF);
  for(Int j=0;j<=k;j++)
    for(Int l=0;l<n;l++)
      chmin(ans,dp[n-1][j][l]);

  cout<<ans<<endl;
  return 0;
}
