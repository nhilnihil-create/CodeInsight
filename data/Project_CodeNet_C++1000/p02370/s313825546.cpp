#include <cstdio>           // printf(), scanf()
#include <vector>
#include <queue>
#include <list>

using namespace std;
static const int MAX_V = 10000;

vector<int> G[MAX_V];
list<int> out;
bool visited[MAX_V];
int indeg[MAX_V];
int V;

void
bfs(int s)
{
	queue<int> q;

	q.push(s);
	visited[s] = true;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		out.push_back(u);
		for (unsigned int i = 0; i < G[u].size(); ++i)
		{
			int v = G[u][i];
			indeg[v]--;

			if (indeg[v] == 0 && !visited[v])
			{
				visited[v] = true;
				q.push(v);
			}
		}
	}
}

void
tsort()
{
	for (int i = 0; i < V; ++i)
		indeg[i] = 0;

	for (int u = 0; u < V; ++u)
	{
		for (unsigned int i = 0; i < G[u].size(); ++i)
		{
			int v = G[u][i];
			indeg[v]++;
		}
	}

	for (int u = 0; u < V; ++u)
	{
		if (indeg[u] == 0 && !visited[u])
			bfs(u);
	}

	for (list<int>::iterator it = out.begin(); it != out.end(); ++it)
		printf("%d\n", *it);
}

int
main(int argc, char** argv)
{
	int E;
	int s, t;

	scanf("%d %d", &V, &E);
	for (int i = 0; i < V; ++i)
		visited[i] = false;

	for (int i = 0; i < E; ++i)
	{
		scanf("%d %d", &s, &t);
		G[s].push_back(t);
	}

	tsort();
	return 0;
}