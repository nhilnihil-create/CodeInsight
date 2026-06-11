#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back

int n,i,dp[200010],a,b,j,ans;
vector<int> adj[200010];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>a>>b;
		if (a>b) swap(a,b);
		adj[b].pb(a);
	}
	dp[1]=1;
	for (i=2;i<n+1;i++)
	{
		dp[i]=dp[i-1]+(i-1);
		a=adj[i].size();
		for (j=0;j<a;j++) dp[i]=dp[i]-(adj[i][j]);
		dp[i]++;
	}
	ans=0;
	for (i=1;i<n+1;i++) ans=ans+dp[i];
	cout<<ans;
}
