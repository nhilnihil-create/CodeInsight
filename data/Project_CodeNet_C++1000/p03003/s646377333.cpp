#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int mod=1e9+7;
int dp[3000][3000];
//dp[i][j] is answer if we use first i of a and j of b
int a[3000],b[3000];
int32_t main()
{	
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];

	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])%mod;
		dp[i][j]+=mod;dp[i][j]%=mod;
		if(a[i]==b[j])
		{
			dp[i][j]=(1+dp[i-1][j-1]+dp[i][j])%mod;
		}
	}
	cout<<(dp[n][m]+1)%mod;

	
}
