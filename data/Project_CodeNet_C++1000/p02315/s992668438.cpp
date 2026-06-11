#include<stdio.h>
#include<string.h>
#include<algorithm>
#define INF 1000000000

int N,W,dp[105][20005],v[105],w[105],i,j;

int dfs(int d,int nw)
{
	if(dp[d][nw]>0)return dp[d][nw];
	if(nw>W)return -INF;
	if(d==N)return 0;
	return dp[d][nw]=std::max(dfs(d+1,nw),dfs(d+1,nw+w[d])+v[d]);
}


int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&N,&W);
	for(i=0;i<N;i++)scanf("%d%d",&v[i],&w[i]);
	//for(i=N;i>=0;i--)
	//{
	//	for(j=0;j<=W;j++)
	//	{
	//		if(i==N)dp[i][j]=0;
	//		else if(j<w[i])dp[i][j]=dp[i+1][j];
	//		else dp[i][j]=std::max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
	//	}
	//}
	//printf("%d\n",dp[0][W]);
	printf("%d\n",dfs(0,0));
	return 0;
}