#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <stack>
#include <queue>
typedef long long ll;
using namespace std;
ll MOD = 1e9+7;
int main(){
  ll i,j,k,n,m;
  cin >> n >> m;
  ll s[n+1];
  ll t[m+1];
  for(i=1;i<=n;i++)cin >> s[i];
  for(i=1;i<=m;i++)cin >> t[i];
  s[0]=-1;
  t[0]=-5;
  ll dp[n+1][m+1];
  for(i=0;i<=m;i++)dp[0][i]=1;
  for(i=0;i<=n;i++)dp[i][0]=1;
  dp[0][0] = 1; //空文字列
  // dp[x][y] := sのx文字目,tのy文字目まで見たときの共通部分列の数
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      if(s[i]!=t[j])dp[i][j]=(dp[i-1][j]+dp[i][j-1]+MOD-dp[i-1][j-1])%MOD;
      if(s[i]==t[j])dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
      dp[i][j]%=MOD;
    }
  }
  cout << dp[n][m]%MOD << endl;
  return 0;
}
