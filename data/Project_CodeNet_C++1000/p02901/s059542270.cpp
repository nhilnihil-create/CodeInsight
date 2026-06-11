#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> a(m),b(m),c(m);
  rep(i,m){
    cin>>a[i]>>b[i];
    rep(j,b[i]){
      int x;
      cin>>x;
      x--;
      c[i]+=1<<x;
    }
  }
  vector<vector<int>> dp(m+1,vector<int>(1<<n,1000000000));
  dp[0][0]=0;
  rep(i,m){
    rep(j,1<<n){
      if(dp[i][j]!=1000000000){
        dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
        dp[i+1][j|c[i]]=min(dp[i+1][j|c[i]],dp[i][j]+a[i]);    
      }
    }
  }
  
  if(dp[m][(1<<n)-1]<1000000000) cout<<dp[m][(1<<n)-1]<<endl;
  else cout<<"-1"<<endl;
}