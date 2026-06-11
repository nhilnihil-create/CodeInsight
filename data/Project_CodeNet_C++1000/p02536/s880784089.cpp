#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
bool vis[N];
int head[N], to[2 * N], nxt[2 * N], num;
void init(int n)
{
	for(int i = 1; i <= n; ++ i) head[i] = 0;
	num = 0;
}
void addedge(int u, int v)
{
	nxt[ ++ num] = head[u];
	to[num] = v;
	head[u] = num;
}
void dfs(int u)
{
	vis[u] = 1;
	for(int e = head[u]; e; e = nxt[e])
	{
		int v = to[e];
		if(vis[v]) continue;
		dfs(v);
	}
}
int main () {
	cin >> n >> m;
	init(n);
	for(int i = 1; i <= m; ++ i)
	{
		int u, v;
		cin >> u >> v;
		addedge(u, v);
		addedge(v, u);
	}
	int num = 0;
	for(int i = 1; i <= n; ++ i)
	{
		if(vis[i]) continue;
		dfs(i);
		num ++;
	}
	cout << num - 1;
    return 0;
}