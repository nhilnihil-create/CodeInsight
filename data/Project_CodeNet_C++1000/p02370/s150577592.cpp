#include <cstdio>           // printf(), scanf()
#include <vector>
#include <list>

using namespace std;
static const int MAX_V = 10000;

vector<int> G[MAX_V];
list<int> out;
bool visited[MAX_V];

void
dfs(int u)
{
	visited[u] = true;
	for (unsigned int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if (!visited[v])
			dfs(v);
	}

	out.push_front(u);
}

int
main(int argc, char** argv)
{
	int V, E;
	int s, t;

	scanf("%d %d", &V, &E);
	for (int i = 0; i < V; ++i)
		visited[i] = false;

	for (int i = 0; i < E; ++i)
	{
		scanf("%d %d", &s, &t);
		G[s].push_back(t);
	}

	for (int i = 0; i < V; ++i)
	{
		if (!visited[i])
			dfs(i);
	}

	for (list<int>::iterator it = out.begin(); it != out.end(); ++it)
		printf("%d\n", *it);

	return 0;
}