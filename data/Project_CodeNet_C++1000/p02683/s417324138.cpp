#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[50][50],c[50],ans[4097],sum[50],cost,cnt;
void dfs(int cur)
{
	if(cur>n)
	{
		bool bad=0;
		for(int i=1;i<=m;i++)
			if(sum[i]<x)
			{
				bad=1;
				break;
			}
		if(bad==0)
			ans[++cnt]=cost;
		return;
	}
	dfs(cur+1);
	for(int i=1;i<=m;i++)
		sum[i]+=a[cur][i];
	cost+=c[cur];
	dfs(cur+1);
	for(int i=1;i<=m;i++)
		sum[i]-=a[cur][i];
	cost-=c[cur];
	return;
}
int main()
{
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	}
	dfs(1);
	sort(ans+1,ans+cnt+1);
	if(ans[1]==0)
		cout<<-1;
	else
		cout<<ans[1];
	return 0;
}