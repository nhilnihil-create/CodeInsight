#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int ans=0;
int main(){
  int n,m;
  cin >> n >> m;
  vector<int> s(n),t(m);
  for(int i=0;i<n;i++) cin >> s[i];
  for(int i=0;i<m;i++) cin >> t[i];
  vector<vector<int>> dp(n+1,vector<int> (m+1,0));
  dp[0][0]=1;
  for(int i=0;i<n;i++){
    int cnt = 0;
    for(int j=0;j<m;j++){
      cnt = (cnt + dp[i][j]) % MOD;
      dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD; 
      if(s[i]==t[j]) dp[i+1][j+1] = (dp[i+1][j+1] + cnt) % MOD;
    }
    dp[i+1][m] = (dp[i+1][m] + dp[i][m])%MOD;
  }
  for(int j=0;j<m+1;j++) ans = (ans + dp[n][j])%MOD;
  cout << ans << endl;
}
