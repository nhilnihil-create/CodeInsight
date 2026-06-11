#include <bits/stdc++.h>

using namespace std;

struct edge {
	int to, cost;
};
typedef pair<int, int> P;

const int INF = 10e8;

void dijkstra(int s, int V, vector<vector<edge>>& G, vector<int>& d)
{
	priority_queue<P, vector<P>, greater<P> > que;
	d.resize(V);
	fill(d.begin(), d.end(), INF);
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty()) {
		P p = que.top();
		que.pop();

		int v = p.second;
		if (d[v] < p.first)
			continue;

		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
	
}

int main(void)
{
	int n, x, y;
	cin >> n >> x >> y;
	vector<vector<edge>> G(n);
	for (int i = 0; i < n; i++) {
		if (i-1>= 0)
			G[i].push_back(edge{i-1, 1});
		if (i+1 < n)
			G[i].push_back(edge{i+1, 1});
		if (i == x-1) {
			G[i].push_back(edge{y-1, 1});
			G[y-1].push_back(edge{x-1, 1});
		}
	}
	vector<vector<int>> d(n);
	for (int i = 0; i < n; i++) {
		dijkstra(i, n, G, d[i]);
	}
	vector<set<pair<int, int>>> s(2000);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			if (d[i][j] > 0 && d[i][j] < INF)
				s[d[i][j]].insert(make_pair(min(i, j), max(i, j)));
		}
	}
	for (int k = 1; k <= n-1; k++) {
		cout << s[k].size() << endl;;
	}

	return 0;
}