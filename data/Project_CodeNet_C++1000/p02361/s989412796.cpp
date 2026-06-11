#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
typedef pair<int, int> P;
static const int INF = 1e9;
static const int SIZE = 100001;
struct edge
{
	int to;
	int cost;
};

vector<edge> G[SIZE];
int d[SIZE];

void solve()
{
	int V, E, start;
	cin >> V >> E >> start;
	for (int i = 0; i < E; ++i)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		edge e;
		e.to = to;
		e.cost = cost;
		G[from].push_back(e);
	}
	for (int i = 0; i < SIZE; ++i)
	{
		d[i] = INF;
	}
	d[start] = 0;
	priority_queue<P, vector<P>, greater<P> > pque;
	pque.push(P(0, start));
	while (!pque.empty())
	{
		P p = pque.top();
		pque.pop();
		int v = p.second;
		for (int i = 0; i < G[v].size(); ++i)
		{
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				pque.push(P(d[e.to], e.to));
			}
		}
	}
	for (int i = 0; i < V; ++i)
	{
		if (d[i] == INF)
		{
			cout << "INF" << endl;
		}
		else
		{
			cout << d[i] << endl;
		}
	}
}

int main()
{
	solve();
	return(0);
}