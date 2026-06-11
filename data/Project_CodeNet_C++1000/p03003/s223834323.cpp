// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,m,ans=0;
  cin >> n >> m;
  ll dp[n+1][m+1];
  fill(dp[0],dp[n+1],0);
  ll s[n],t[m];
  for(int i=0;i<n;i++){
    cin >> s[i];
  }
  for(int i=0;i<m;i++){
    cin >> t[i];
  }
  for(int i=0;i<=n;i++){
    dp[i][0]=1;
  }
  for(int i=0;i<=m;i++){
    dp[0][i]=1;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      dp[i+1][j+1] = dp[i][j+1]+dp[i+1][j];
      if(s[i]!=t[j]){
        dp[i+1][j+1] -= dp[i][j];
      }
      dp[i+1][j+1] %= MOD;
    }
  }
  while(dp[n][m]<0){
    dp[n][m] += MOD;
    dp[n][m] %= MOD;
  }
  cout << dp[n][m] << endl;
}
