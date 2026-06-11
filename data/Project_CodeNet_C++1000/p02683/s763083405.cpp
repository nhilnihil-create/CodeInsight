#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,x;
	cin>>n>>m>>x;
	int c[50],a[50][50],sum[50],ans[4097],cnt=0;
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	}
	for(int i=0;i<(1<<n);i++)
	{
		memset(sum,0,sizeof(sum));
		int cost=0;
		for(int j=0;j<n;j++)
			if(i&(1<<j))
			{
				cost+=c[j+1];
				for(int k=1;k<=m;k++)
					sum[k]+=a[j+1][k];
			}
		bool bad=0;
		for(int j=1;j<=m;j++)
			if(sum[j]<x)
			{
				bad=1;
				break;
			}
		if(!bad)
			ans[++cnt]=cost;
	}
	sort(ans+1,ans+cnt+1);
	if(ans[1]==0)
		cout<<-1;
	else
		cout<<ans[1];
	return 0;
}