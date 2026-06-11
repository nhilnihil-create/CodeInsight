#include <bits/stdc++.h>
using namespace std;

const int INF = 1'000'000'000;
struct Edge { int to, cost; };
using P=pair<int, int>;

int V, E;
vector<vector<Edge>> graph;
vector<int> dist;


void Dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({ 0,s });
	dist[s] = 0;

	while (!pq.empty()) {
		P p = pq.top(); pq.pop();
		int v = p.second;
		if (dist[v] < p.first)continue;
		for (auto e : graph[v]) {
			if (dist[e.to] > dist[v] + e.cost) {
				dist[e.to] = dist[v] + e.cost;
				pq.push({ dist[e.to],e.to });
			}
		}
	}
}

int main() {
	int r;
	cin >> V >> E >> r;
	graph = vector<vector<Edge>>(V);
	dist = vector<int>(V, INF);
	for (int i = 0; i < E; i++) {
		int s, t, d;
		cin >> s >> t >> d;
		graph[s].push_back({ t,d });
	}

	Dijkstra(r);
	for (auto d : dist) {
		if (d == INF)puts("INF");
		else cout << d << endl;
	}
}
