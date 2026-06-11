#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int main()
{
  int H,N;scanf("%d %d\n",&H,&N);
  int A[N],B[N];
  vector<vector<int>> dp(N+1,vector<int>(H+1,INF));
  for(int i=0;i<N;i++)dp[i][0]=0;
  for(int i=0;i<N;i++)scanf("%d %d\n",&A[i],&B[i]);
  for(int i=0;i<N;i++)for(int j=0;j<H+1;j++)
  {
    if(j-A[i]<0)dp[i+1][j]=dp[i][j];
    else dp[i+1][j]=min(dp[i][j],dp[i+1][j-A[i]]+B[i]);
  }
  int ans=dp[N][H];
  for(int i=0;i<H+1;i++)for(int j=0;j<N;j++)if(i+A[j]>=H)ans=min(ans,dp[N][i]+B[j]);
  printf("%d",ans);
}