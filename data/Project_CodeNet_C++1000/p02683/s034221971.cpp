#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
	int pri;
	int a[18];
} st[18];
int ans=1e9;
int b[18];
int d[18];
int n,m,x;
int len;
void dfs(int p)
{
	if(p==len+1)
	{
		int sum=0;
		memset(d,0,sizeof(d));
		for(int i=1;i<=len;i++)
		{
			sum+=st[b[i]].pri;
			for(int j=1;j<=m;j++)
			{
				d[j]+=st[b[i]].a[j];
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(d[i]<x) return ;
		}
		ans=min(ans,sum);
		return ;
	}
	for(int i=b[p-1]+1;i<=n;i++)
	{
		b[p]=i;
		dfs(p+1);
	}
}
int main()
{
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>st[i].pri;
		for(int j=1;j<=m;j++)
		{
			cin>>st[i].a[j];
		}
	}
	for(len=1;len<=n;len++)
	{
		b[0]=0;
		dfs(1);
	}
	if(ans==1e9) cout<<-1<<"\n";
	else cout<<ans<<"\n";
	return 0;
}