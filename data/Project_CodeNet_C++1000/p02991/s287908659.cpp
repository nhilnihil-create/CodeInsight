#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
using namespace std;

int n, m;
vector < pair < int, int > > g[100013][3];
map < pair < int, int >, int > dist;
map < pair < int, int >, bool > used;

void bfs (pair < int, int > root) {
	queue < pair < int, int > > q;
	used[root] = 1;
	dist[root] = 0;
	q.push(root);
	while (!q.empty()) {
		pair < int, int > u = q.front();
		q.pop();
		for (auto v: g[u.first][u.second]) {
			if (!used[v]) {
				used[v] = 1;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

signed main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		for (int j = 0; j < 3; ++j)
			g[u][j].push_back(make_pair(v, (j + 1) % 3));
	}
	int s, t;
	cin >> s >> t;
	bfs(make_pair(s, 0));
	if (used[make_pair(t, 0)])
		cout << dist[make_pair(t, 0)] / 3 << '\n';
	else
		cout << "-1\n";
}
