#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
int main(){
  const int INF=1000000000;
  int n,m,a[1010],b,c[1010],d,i,j,dp[(1<<13)];
  scanf("%d %d\n",&n,&m);
  for(i=0;i<m;i++){
    c[i]=0;
  }
  for(i=0;i<(1<<n);i++){
    dp[i]=INF;
  }
  for(i=0;i<m;i++){
    scanf("%d %d\n",&a[i],&b);
    for(j=0;j<b;j++){
      scanf("%d ",&d);
      d--;
      c[i]|=(1<<d);
    }
  }
  dp[0]=0;
  for(i=0;i<m;i++){
    for(j=0;j<(1<<n);j++){
      dp[j|c[i]]=min(dp[j|c[i]],dp[j]+a[i]);
    }
  }
  if(dp[(1<<n)-1]==INF){
    printf("-1\n");
    return 0;
  }
  printf("%d\n",dp[(1<<n)-1]);
  return 0;
}