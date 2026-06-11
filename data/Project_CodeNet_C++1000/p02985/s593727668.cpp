#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;

int n,k,cnt=0,ans=1;
int head[200005],depth[100005],a[100005];

struct node
{
	int u,v;
}tmp[100005];

struct edge
{
	int next;
	int to;
}e[200005];

inline void add_edge(int u,int v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}

inline void dfs(int now,int fath)
{
	depth[now]=depth[fath]+1;
	for (int i=head[now];i;i=e[i].next)
	{
		if (e[i].to!=fath)  dfs(e[i].to,now);
	}
}

inline void dfs2(int now,int fath)
{
	if (depth[now]==2)  a[now]--;
	else if (depth[now]>=3)  a[now]-=2;
	
	int flag=0,last;
	for (int i=head[now];i;i=e[i].next)
	{
		if (e[i].to!=fath)
		{
			if (flag==0)
			{
				last=a[e[i].to];
				flag=1;
				continue;
			}
			a[e[i].to]=last-1;
			last=a[e[i].to];
		}
	}
	for (int i=head[now];i;i=e[i].next)
	{
		if (e[i].to!=fath)  dfs2(e[i].to,now);
	}
}

signed main()
{
	cin>>n>>k;
	for (int i=1;i<n;i++)  cin>>tmp[i].u>>tmp[i].v;
	for (int i=1;i<=n;i++)  a[i]=k;
	for (int i=n;i>=1;i--)
	{
		add_edge(tmp[i].u,tmp[i].v);
		add_edge(tmp[i].v,tmp[i].u);
	}
	dfs(1,0);
	dfs2(1,0);
	
	for (int i=1;i<=n;i++)
	{
		int gx=max(a[i],0ll);
		ans=(ans*gx)%mod;
	}
	cout<<ans<<endl;
	
	return 0;
}