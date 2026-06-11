#include <bits/stdc++.h>
using namespace std;
int n,m,q;
int sum,a[105],b[105],c[105],d[105],k[105];
void dfs(int x)
{
	if(x>n)
	{
		int res=0;
		for(int i=0;i<q;i++)
		{
			if(k[b[i]]-k[a[i]]==c[i])
				res+=d[i];
		}
		sum=max(sum,res);
		return;
	}
	for(int i=k[x-1];i<=m;++i)
	{
		k[x]=i;
		dfs(x+1);
	}
}
int main()
{
	cin>>n>>m>>q;
	for(int i=0;i<q;i++)
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	k[0]=1;
	dfs(1);
	cout<<sum;

	return 0;
}