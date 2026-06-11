#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <list>
using namespace std;
const int INF = 1 << 30;
const int NIL = -1;
const int MAXV = 10005;
const int MAXE = 100005;

struct Edge {
	int to, next;
	Edge() { next = -1; }
} edge[MAXE];

list<int> ans;
int head[MAXE];
int indegree[MAXV];
bool vis[MAXV];
int cnt;

void bfs(int u)
{
	queue<int> q;
	vis[u] = true;
	q.push(u);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		ans.push_back(u);
		for (int i = head[u]; i != NIL; i = edge[i].next)
		{
			u = edge[i].to;
			if (!vis[u] && --indegree[u] == 0)
			{
				vis[u] = true;
				q.push(u);
			}
		}
	}
	
}

void topologicalSort(int n)
{
	for (int i = 0; i < n; ++i)
		vis[i] = false;

	for (int i = 0; i < n; ++i)
	{
		if (indegree[i] == 0 && !vis[i])
			bfs(i);
	}
}

void add(int u, int v)
{
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}


int main(void)
{
	
	int V, E, s, t;
	scanf("%d%d", &V, &E);
	cnt = 0;
	memset(head, NIL, sizeof(int) * (E + 1));
	for (int i = 0; i < E; ++i)
	{
		scanf("%d%d", &s, &t);
		++indegree[t];
		add(s, t);
	}
	topologicalSort(V);
	for (list<int>::iterator it = ans.begin(); it != ans.end(); ++it)
		printf("%d\n", *it);
	return 0;
}