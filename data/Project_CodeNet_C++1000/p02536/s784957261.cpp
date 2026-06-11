#include<bits/stdc++.h>
using namespace std;

const int maxn = 100005;

vector<int> G[maxn];
int vis[maxn];

void DFS(int x)
{
	vis[x] = 1;
	for(int i = 0;i < G[x].size();++i)
	{
		int v = G[x][i];
		if(vis[v] == 0) DFS(v);
	}
}
int main()
{
	int N,M;
	cin>>N>>M;
	while(M--)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int cnt = 0;
	for(int i = 1;i <= N;++i)
	{
		if(vis[i] == 0)
		{
			DFS(i);
			cnt++;
		}
	}
	cout<<cnt-1;
	return 0;
} 