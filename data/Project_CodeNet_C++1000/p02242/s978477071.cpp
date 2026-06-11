#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

const int INF = (1 << 30) - 1;
const ll INF64 = ((ll)1 << 62) - 1;
const double PI = 3.1415926535897932384626433832795;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < n; i++) {
		int k, v;
		cin >> k >> v;
		for (int j = 0; j < v; j++) {
			int u, c;
			cin >> u >> c;
			g[k].emplace_back(u, c);
		}
	}

	vector<int> dist(n, INF);
	dist[0] = 0;
	vector<bool> used(n);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.emplace(0, 0);
	while (!pq.empty()) {
		pair<int, int> p = pq.top(); pq.pop();
		int v = p.second;

		if (dist[v] < p.first) {
			continue;
		}

		for (auto e : g[v]) {
			int to = e.first;
			int cost = e.second;
			if (dist[to] > dist[v] + cost) {
				dist[to] = dist[v] + cost;
				pq.emplace(dist[to], to);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << i << " " << dist[i] << endl;
	}
	return 0;
}

