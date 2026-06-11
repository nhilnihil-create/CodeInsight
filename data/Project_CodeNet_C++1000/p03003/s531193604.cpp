#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000007
#define ll long long int

int main(){
  int n,m;
  cin>>n>>m;
  ll s[n],t[m];
  for(int i=0;i<n;i++) cin>>s[i];
  for(int i=0;i<m;i++) cin>>t[i];
  ll dp[3000][3000];
  memset(dp,0,sizeof dp);
  dp[0][0]=1;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(i<n && j<m && s[i]==t[j]) dp[i+1][j+1]+=dp[i][j];
      dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MAX;
      dp[i][j+1]=(dp[i][j+1]+dp[i][j])%MAX;
      dp[i+1][j+1]=(dp[i+1][j+1]-dp[i][j])%MAX;
    }
  }
  if(dp[n][m]<0) dp[n][m]+=MAX;
  cout<<dp[n][m];
}