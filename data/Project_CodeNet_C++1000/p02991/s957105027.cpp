#include "bits/stdc++.h"

typedef long long ll;

const int size = 100005;

std::vector<int> g[size];

bool visited[size][3];

int dfs(int s, int e)
{
	// Vertex, mod
	std::queue<std::pair<int, int>> q;
	q.push({ s, 0 });
	while (!q.empty())
	{
		int vert = q.front().first;
		int ken = q.front().second;
		q.pop();
		if (vert == e && ken % 3 == 0)
		{
			return ken / 3;
		}
		if (visited[vert][ken % 3])
		{
			continue;
		}
		visited[vert][ken % 3] = true;
		for (int nV : g[vert])
		{
			q.push({ nV, ken + 1 });
		}
	}
	return -1;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
	}
	int s, e;
	scanf("%d%d", &s, &e);
	printf("%d\n", dfs(s, e));
	return 0;
}