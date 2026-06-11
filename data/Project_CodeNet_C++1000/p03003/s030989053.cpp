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
  ll dp2[n+1][m+1];
  for(i=0;i<=m;i++)dp2[0][i]=0;
  for(i=0;i<=n;i++)dp2[i][0]=0;
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      dp2[i][j]=max(dp2[i-1][j],dp2[i][j-1]);
      if(s[i]==t[j])dp2[i][j]=dp2[i-1][j-1]+1;
      //dp[i][j]%=MOD;
    }
  }
  ll dp[n+1][m+1];
  for(i=0;i<=m;i++)dp[0][i]=0;
  for(i=0;i<=n;i++)dp[i][0]=0;
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      if(s[i]!=t[j])dp[i][j]=(dp[i-1][j]+dp[i][j-1]+MOD-dp[i-1][j-1])%MOD;
      if(s[i]==t[j])dp[i][j]=dp[i][j-1]+dp[i-1][j]+1;
      dp[i][j]%=MOD;
    }
  }
  cout << (dp[n][m]+1)%MOD << endl;
  return 0;
}
