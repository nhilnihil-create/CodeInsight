#include<stdio.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=100;
int a[maxn][maxn],n,m,k,g[maxn][maxn];
char ss[maxn];
bool f[maxn];
long long ans;
bool judge()
{
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(f[i])continue;
		for(int j=1;j<=m;++j)
		{
			if(f[j+n])continue;
			if(a[i][j])cnt++;
		}
	}
	if(cnt==k)return 1;
	return 0;
}
void dfs(int x)
{
	if(x==n+m+1)
	{
		if(judge())ans++;
		return;
	}
	f[x]=1;
	dfs(x+1);
	f[x]=0;
	dfs(x+1);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",ss);
		for(int j=1;j<=m;++j)
		{
			if(ss[j-1]=='.')a[i][j]=0;
			else a[i][j]=1;
			g[i][j]=a[i][j];
		}
	}
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
