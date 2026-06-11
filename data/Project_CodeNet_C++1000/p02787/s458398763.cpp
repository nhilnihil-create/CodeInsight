#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
template<class T> inline void chmin(T& a,T b){ if(a>b) a=b;}
const ll INF=1LL<<60;

int main(void){
  int h,n; cin>>h>>n;
  vector<int> a(n),b(n);
  for(int i=0; i<n; ++i) cin>>a[i]>>b[i];
  vector<vector<ll>> dp(n+1,vector<ll>(h+1,INF));
  dp[0][0]=0;
  for(int i=0; i<n; ++i)
    for(int j=0; j<=h; ++j){
      chmin(dp[i+1][j],dp[i][j]);
      chmin(dp[i+1][min(j+a[i],h)],dp[i+1][j]+b[i]);
    }
  cout<<dp[n][h];
  return 0;
}