#include <bits/stdc++.h>
using namespace std;
int arr[305];
long long dp[305][305];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n+1;i++)
	{
		if (i!=n+1)
		scanf("%d",&arr[i]);
		for (int j=0;j<=n;j++)
		dp[i][j]=1e18;
		for (int j=0;j<i;j++)
		{
			for (int l=0;l<=j;l++)
			dp[i][j]=min(dp[i][j],dp[i-l-1][j-l]+max(arr[i]-arr[i-l-1],0));
		}
	}
	printf("%lld",dp[n+1][k]);
}