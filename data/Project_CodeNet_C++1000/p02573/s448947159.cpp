#include <cstdio>
#include <queue>
#include <vector>
#define maxn 200005
using namespace std;

vector<int> G[maxn];
bool vis[maxn];

int bfs(int x)
{
	queue<int> q;
	q.push(x);
	int cnt = 0;
	while(!q.empty())
	{
		x = q.front(); q.pop();
		if(vis[x]) continue;
		vis[x] = true, cnt ++;
		for(int v: G[x])
			q.push(v);
	}
	return cnt;
}

int main(int argc, char** argv)
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int ans = bfs(0);
	for(int i=1; i<n; i++)
		if(!vis[i])
		{
			int cnt = bfs(i);
			if(cnt > ans)
				ans = cnt;
		}
	printf("%d\n", ans);
	return 0;
}