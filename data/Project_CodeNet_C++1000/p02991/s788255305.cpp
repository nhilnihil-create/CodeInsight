#include<cstdio>
#include<vector>
#include<queue>
#define f(x,k) 3*(x-1)+k+1
std::vector<int> a[300005];
int n,m,s,t,dis[300005];
void add(int x,int y){a[x].push_back(y);}
void bfs(int s)
{
	std::queue<int> q;
	for (int i=1;i<=3*n;i++) dis[i]=1000000000;
	dis[s]=0;q.push(s);
	while (!q.empty())
	{
		int v=q.front();q.pop();
		for (int i=0;i<a[v].size();i++)
		{
			int u=a[v][i];
			if (dis[v]+1<dis[u]) dis[u]=dis[v]+1,q.push(u);
	    }
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(f(x,0),f(y,1));
		add(f(x,1),f(y,2));
		add(f(x,2),f(y,0));
	}
	scanf("%d%d",&s,&t);
	bfs(f(s,0));
	printf("%d\n",dis[f(t,0)]!=1000000000?dis[f(t,0)]/3:-1);
}