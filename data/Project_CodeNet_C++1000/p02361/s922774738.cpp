#include <bits/stdc++.h>
#define INF 1000000000
#define MAX_V 100000
using namespace std;


int V, E, r;
int d[MAX_V];
struct edge {
	int to, cost;
	edge(int to_, int cost_) : to(to_), cost(cost_) {}
};
typedef pair<int, int> P;
vector<edge> G[MAX_V];

void Dijkstra(int start) {
	fill(d, d + V, INF);
	priority_queue<P, vector<P>, greater<P>> que;
	d[start] = 0;
	que.push(P(0, start));

	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;
		if (d[v] < p.first) continue;
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

int main()
{
	int r;
	cin >> V >> E >> r;
	for (int i = 0, s, t, d; i < E; i++) {
		cin >> s >> t >> d;
		G[s].push_back(edge(t, d));
	}
	Dijkstra(r);
	for (int i = 0; i < V; i++) {
		if (d[i] == INF)
			cout << "INF" << endl;
		else
			cout << d[i] << endl;
	}
	return 0;
}