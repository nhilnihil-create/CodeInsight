#include <cstdio>

using namespace std;

int n,num[100];
long long int dp[100][21];

int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",&num[i]);
  dp[0][num[0]]=1;

  for(int i=1;i<n;i++){
    for(int j=0;j<21;j++){
      if(dp[i-1][j]!=0){
        if(0<=j+num[i] && j+num[i]<=20){
          dp[i][j+num[i]]+=dp[i-1][j];
        }
        if(0<=j-num[i] && j-num[i]<=20){
          dp[i][j-num[i]]+=dp[i-1][j];
        }
      }
    }
  }

  long long int ans=dp[n-2][num[n-1]];

  printf("%lld\n",ans);

  return 0;
}