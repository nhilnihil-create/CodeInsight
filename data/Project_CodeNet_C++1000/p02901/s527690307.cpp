#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int inf = 1001001001;
int main(){
  int N,M,i,j,k;scanf("%d%d",&N,&M);
  int dp[M+1][1<<N];
  fill(dp[0],dp[0]+(1<<N),inf);dp[0][0] = 0;
  dp[0][0] = 0;
  int a,b,c,plus;
  for(i=0;i<M;i++){
    for(j=0;j<(1<<N);j++) dp[i+1][j] = dp[i][j];
    scanf("%d%d",&a,&b);plus = 0;
    for(k=0;k<b;k++){
      scanf("%d",&c);c--;
      plus += 1<<c;
    }
    for(j=0;j<(1<<N);j++) dp[i+1][j|plus] = min(dp[i+1][j|plus],dp[i][j]+a);
  }
  if(dp[M][(1<<N)-1] == inf) printf("-1\n");
  else printf("%d\n",dp[M][(1<<N)-1]);
}
