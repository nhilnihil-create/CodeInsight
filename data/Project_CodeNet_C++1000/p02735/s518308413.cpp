#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
  ll n,m;
  cin>>n>>m;
  vector<vector<ll>> mat(n,vector<ll>(m));
  for(ll i=0;i<n;i++)
    for(ll j=0;j<m;j++)
    {char ch; cin>>ch; mat[i][j] = (ch=='.'?1:0);}
  vector<vector<ll>> dp (n,vector<ll>(m));
  if(mat[0][0] == 0)
    dp[0][0]++;
  for( ll i=1;i<m;i++){
    if(mat[0][i] == 0 && mat[0][i-1]!=0)
      dp[0][i] = dp[0][i-1]+1;
    else dp[0][i] = dp[0][i-1];
  }
  for( ll i=1;i<n;i++){
    if(mat[i][0] == 0 && mat[i-1][0]!=0)
      dp[i][0] = dp[i-1][0]+1;
    else dp[i][0] = dp[i-1][0];
  }
  for(ll i=1;i<n;i++){
    for(ll j=1;j<m;j++){
      if(mat[i][j])
        dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
      else
        dp[i][j] = min(dp[i-1][j] + mat[i-1][j],dp[i][j-1]+ mat[i][j-1]);
    }
  }
  cout<<dp[n-1][m-1];
}