#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> G[101];
bool visit[101];
int n, u, k, m;
int dist[101];

void bfs()
{
	int root = 1;
	queue<int> que;
	que.push(root);
	dist[root] = 0;
 visit[root] = true;
	while (!que.empty())
	{
		int node = que.front();
		que.pop();
		for (int i = 0; i < G[node].size(); i++)
		{
			int next = G[node][i];
			if (!visit[next])
			{
				visit[next] = true;
				que.push(next);
				dist[next] = dist[node] + 1;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < sizeof(dist) / sizeof(dist[0]); i++)
		dist[i] = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &u, &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%d", &m);
			G[u].push_back(m);
		}
	}
	bfs();
	for (int i = 1; i <= n; i++)
		printf("%d %d\n", i, dist[i]);

	return 0;
}

