#include <bits/stdc++.h>
using namespace std;
int n,m,x,ans=0;
int c[21],a[21][21],sum[21],mini=1200007;
bool check()
{
	for(int i=1;i<=m;i++)
	{
		if(sum[i]<x) return 0;
	}
	return 1;
}
void dfs(int cur)
{
	if(check()==1)
	{
		if(ans<mini) mini=ans;
		return;
	}
	if(cur>n) return;
	for(int i=1;i<=m;i++) sum[i]+=a[cur][i];
	ans+=c[cur];
	dfs(cur+1);
	for(int i=1;i<=m;i++) sum[i]-=a[cur][i];
	ans-=c[cur];
	dfs(cur+1);
	return;
}
int main()
{
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		for(int j=1;j<=m;j++) cin>>a[i][j];
	}
	dfs(1);
	if(mini==1200007) cout<<-1;
	else cout<<mini;
    return 0;
}