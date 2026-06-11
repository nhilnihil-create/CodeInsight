#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<bitset>
#define maxn 100005
#define mid ((nl+nr)>>1)
using namespace std;
typedef long long ll;
int n,m;
int fa[maxn];
int getfa(int now)
{
	return fa[now]==now ? now : fa[now]=getfa(fa[now]);
}
int vis[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int xx=getfa(x),yy=getfa(y);
		if(xx!=yy)
		{
			fa[xx]=yy;
		}
	}
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		int xx=getfa(i);
		if(!vis[xx]) vis[xx]=1,ans++;
	}
	printf("%d\n",ans);
}