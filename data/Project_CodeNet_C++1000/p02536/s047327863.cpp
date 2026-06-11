#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,a[N],c;
vector<int>e[N];
void dfs(int u)
{
	a[u]=1;
	for(auto v:e[u])
		if(!a[v])
			dfs(v);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
		{
			c++;
			dfs(i);
		}
	}
	printf("%d\n",c-1);
	return 0;
}
