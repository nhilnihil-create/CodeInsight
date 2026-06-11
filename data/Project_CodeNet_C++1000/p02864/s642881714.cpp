#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
const int maxn=305;
ll dp[maxn][maxn];int id[maxn][maxn];
ll h[maxn];
int main()
{
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&h[i]);
	}
	memset(id,0,sizeof id);
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=0;
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=1e18;
		}
	}
	dp[0][0]=0;
	dp[1][1]=h[1];
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(j==1)
			{
				dp[i][j]=h[i];continue;
			}
			for(int z=1;z<i;z++)
			{
				dp[i][j]=min(dp[i][j],dp[z][j-1]+max(0ll,h[i]-h[z]));
				//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			}
		}
	}
	//for(int i=0;i<=n;i++)
	//{
	//	for(int j=0;j<=n;j++)
	//	{
	//		cout<<dp[i][j]<<" ";
	//	}
	//	cout<<endl;
	//}
	ll ans=1e18;
	for(int i=1;i<=n;i++) ans=min(ans,dp[i][n-k]);
	cout<<ans<<endl;
 } 
 /*
 
 0 2
 0 2 3
 0 2 3 4
 0 1 2 3 4
 */