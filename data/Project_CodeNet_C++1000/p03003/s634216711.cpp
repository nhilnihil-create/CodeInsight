#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int main(){
  int n,m;cin >> n >> m;
  vector<int> s(n),t(m);
  for(int i=0;i<n;i++){
    cin >> s[i];
  }
  for(int j=0;j<m;j++){
    cin >> t[j];
  }
  vector<vector<ll>> dp(n+1,vector<ll>(m+1));
  dp[0][0]=1;
  for(int i=0;i<=n;i++){
    dp[i][0]=1;
  }
  for(int i=0;i<=m;i++){
    dp[0][i]=1;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(s[i]==t[j]){
        dp[i+1][j+1]=(dp[i+1][j]+dp[i][j+1])%mod;
      }
      else{
        dp[i+1][j+1]=(dp[i+1][j]+dp[i][j+1]-dp[i][j]+mod)%mod;
      }
    }
  }
  cout << dp[n][m] << endl;
}