#include <stdio.h>
#include<map>
#include<vector>
using namespace std;

map<pair<int, int>, int> seen, dist;

int dfs(map<pair<int, int>, vector<pair<int, int>>> &edge, pair<int, int> now)
{
	if (seen[now] == 2)
		return dist[now];
	seen[now] = 1;
	for (pair<int,int> &e : edge[now])
	{
		if (seen[e] == 1)
		{
			printf("-1\n");
			exit(0);
		}
		dist[now] = max(dist[now], dfs(edge, e) + 1);
	}
	seen[now] = 2;
	return dist[now];
}

int main()
{
	int N;
	scanf("%d", &N);
	
	map<pair<int, int>, vector<pair<int, int>>> edge;
	for (int i = 0; i < N; i++)
	{
		pair<int, int> now = {0, 0};
		for (int j = 0; j < N - 1; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			tmp--;
			int gr = max(i, tmp);
			int sm = min(i, tmp);

			pair<int, int> next = make_pair(sm, gr);
			edge[now].push_back(next);
			now = next;
		}
	}

	printf("%d\n", dfs(edge, make_pair(0, 0)));
}