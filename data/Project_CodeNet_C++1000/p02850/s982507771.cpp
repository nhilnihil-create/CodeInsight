#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,k=0,cnt=0,u,v,maxv=0,pos;
int head[100005],de[100005];

map<pair<int,int>,int> m;

struct node
{
	int u,v;
}a[200005];

struct edge
{
	int next;
	int to;
	int color;
}e[200005];

inline void add_edge(int u,int v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}

inline void dfs(int now,int fath,int last)
{
	int num=0;
	for (int i=head[now];i;i=e[i].next)
	{
		if (e[i].to!=fath)
		{
			num++;
			while (num==last)  num++;
			e[i].color=num;
			m[make_pair(now,e[i].to)]=e[i].color;
			dfs(e[i].to,now,num);
		}
	}
}

signed main()
{
	cin>>n;
	for (int i=1;i<n;i++)
	{
		cin>>u>>v;
		a[i].u=u,a[i].v=v;
		add_edge(u,v);
		add_edge(v,u);
		de[u]++,de[v]++;
	}
	for (int i=1;i<=n;i++)
	{
		if (de[i]>maxv)  maxv=de[i],pos=i;
	}
	for (int i=head[pos];i;i=e[i].next)  e[i].color=++k,m[make_pair(pos,e[i].to)]=e[i].color;
	for (int i=head[pos];i;i=e[i].next)  dfs(e[i].to,pos,e[i].color);
	
	cout<<k<<endl;
	for (int i=1;i<n;i++)
	{
		if (m[make_pair(a[i].u,a[i].v)]==0)  cout<<m[make_pair(a[i].v,a[i].u)]<<endl;
		else cout<<m[make_pair(a[i].u,a[i].v)]<<endl;
	}
	return 0;
}