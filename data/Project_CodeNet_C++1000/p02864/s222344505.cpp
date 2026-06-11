#include<bits/stdc++.h>
using namespace std;
static const int64_t INF=10000000000000;
static const int64_t zero=0;
int64_t N,K;
int64_t dp[305][305][305];
int main(){
  for(int i=0;i<305;i++)
    for(int j=0;j<305;j++)
      for(int k=0;k<305;k++)
        dp[i][j][k]=INF;
  cin>>N>>K;
  vector<int64_t>H(N+1);H[0]=0;
  for(int i=1;i<=N;i++)
    cin>>H.at(i);
  dp[0][0][0]=0;
  for(int i=1;i<=N;i++)
    dp[i][i][0]=dp[i-1][i-1][0]+max(zero,H[i]-H[i-1]);
    for(int i=1;i<=N;i++)
      for(int j=0;j<=i;j++)
      for(int k=1;k<=K;k++){
      if(i!=j){
      dp[i][j][k]=dp[i-1][j][k-1];
      }else{
        int64_t a=INF;
        for(int l=0;l<=i-1;l++)
         if(0<=k-i+1+l){
      if(dp[l][l][k-i+1+l]+max(zero,H[i]-H[l])<a)
        a=dp[l][l][k-i+1+l]+max(zero,H[i]-H[l]);
      }
     dp[i][i][k]=a;
    }
      
      }int64_t ans=INF;
         for(int j=0;j<=N;j++){
         if(dp[N][j][K]<ans)ans=dp[N][j][K];
         }cout<<ans<<endl;
  return 0;
}