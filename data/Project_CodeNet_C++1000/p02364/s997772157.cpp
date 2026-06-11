#include <bits/stdc++.h>
#define INF 1000000000
#define MAX_V 10000
#define MAX_E 100000
using namespace std;
typedef pair<int, int> P;
struct edge {
	int to, cost;
	edge(int to_, int cost_) : to(to_), cost(cost_) {}
};

int V, E;
vector<edge> G[MAX_V];

int Prim() {
	int res = 0;
	bool used[MAX_V];
	priority_queue<P, vector<P>, greater<P>> que;
	for (int i = 0; i < V; i++) {
		used[i] = false;
	}
	que.push(P(0, 0));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;
		if (used[v]) continue;
		used[v] = true;
		res += p.first;
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			que.push(P(e.cost, e.to));
		}
	}
	return res;
}

int main()
{
	cin >> V >> E;
	for (int i = 0, s, t, c; i < E; i++) {
		cin >> s >> t >> c;
		G[s].push_back(edge(t, c));
		G[t].push_back(edge(s, c));
	}
	cout << Prim() << endl;
	return 0;
}