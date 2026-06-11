#include <bits/stdc++.h>
using namespace std;

long long int dp[1005][(1<<12)+5];
int main(){
  int n,m;
  cin >> n >> m;//見栄を張らずにループで埋める
  for(int i=0;i<1005;i++)for(int j=0;j<(1<<12)+5;j++)dp[i][j]=1e18;
  dp[0][0]=0;
  long long int a;
  int b,c,d;
  for(int i=0;i<m;i++){
    cin >> a >> b;
    c=0;
    for(int j=0;j<b;j++){
      cin >> d;
      c+=(1<<(d-1));
    }
    for(int j=0;j<(1<<n);j++){//最初に埋めた分を小さくできそうなら更新する
      if(dp[i+1][j]>dp[i][j])dp[i+1][j]=dp[i][j];
      if(dp[i+1][j|c]>dp[i][j]+a)dp[i+1][j|c]=dp[i][j]+a;
    }
  }
  if(dp[m][(1<<n)-1]==1e18)cout << -1 << endl;
  else cout << dp[m][(1<<n)-1] << endl;
}

