#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;

int N,M,i,cnt;

int main(void){
  cin >> N >> M;
  int a[M];
  for(i=0;i<M;i++){
    cin >> a[i];
  }
  int b[N+1];
  for(i=0;i<=N;i++){
    b[i]=1;
  }
  for(i=0;i<M;i++){
    b[a[i]]=0;
  }
  int dp[N+1];
  for(i=0;i<=N;i++){
    dp[i]=0;
  }
  dp[0]=1;
  if(b[0]==1){
    dp[1]=1;
  }

  for(i=2;i<=N;i++){
    if(b[i-1]==1){
      dp[i] = dp[i] + dp[i-1];
    }
    if(b[i-2]==1){
      dp[i] = dp[i] + dp[i-2];
    }
    dp[i] = dp[i]%1000000007;
  }
  cnt = dp[N]; 
  
  
  printf("%d\n",cnt);
  return 0;
}
