#include <stdio.h>
int dp[50002];
int min(int a,int b){
  if(a<b)return a;
  else return b;
}
int main(){
  int n,m;
  int i,j;
  int c[22];
  int count=0;
  int inf=10000000;
  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++)scanf("%d",&c[i]);
 
  for(i=0;i<=n;i++)dp[i]=inf;
  dp[0]=0;
   
  for(i=0;i<m;i++){
    for(j=c[i];j<=n;j++){
      dp[j]=min(dp[j],dp[j-c[i]]+1);
    }
  }
  
  printf("%d\n",dp[n]);
  return 0;
}