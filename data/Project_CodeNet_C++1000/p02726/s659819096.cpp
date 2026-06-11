#include <bits/stdc++.h>
using namespace std;

const int N = 2e3;
int dis[N+10][N+10];
vector<int>g[N+10];
int vis[N+10],ans[N+10];

int main()
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<n;i++){
		g[i].push_back(i+1);
		g[i+1].push_back(i);
	}
	g[x].push_back(y);
	g[y].push_back(x);
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		vis[i] = 1;
		queue<int>q;
		q.push(i);
		while(!q.empty())
		{
			int v = q.front();
			q.pop();
			for(auto it:g[v])
			{
				if(!vis[it]){
					vis[it] = vis[v]+1;
					dis[i][it] = vis[it]-1;
					q.push(it);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans[dis[i][j]]++;
		}
	}
	for(int i=1;i<n;i++){
		printf("%d\n",ans[i]);
	}
}
