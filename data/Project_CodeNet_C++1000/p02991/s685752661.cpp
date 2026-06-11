#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define debug cerr <<
#define ll long long
// #define int long long
#define FOR(i, x, y) for(int i = x; i <= y; ++i)
#define pb push_back
#define eb emplace_back
#define Size(v) (int)v.size()

using namespace std;
// using namespace __gnu_pbds;

// Always
const int nax = 1e5 + 5, INF = 1e9 + 7;
int n, m, s, t, dist[nax];
bool vis[nax][4], v[nax];
vector<int> g[nax], adj[nax];

void bfs() {
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	v[s] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto &c : adj[u]) {
			if (v[c]) continue;
			v[c] = true;
			dist[c] = dist[u] + 1;
			q.push(c);
		}
	}
}

void solve() {
	fill(dist, dist + nax, INF);
	cin >> n >> m;
	FOR (i, 1, m) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
	}
	cin >> s >> t;
	queue<int> que;
	que.push(s);
	dist[s] = 0;
	vis[s][0] = true;
	while (!que.empty()) {
		int i = que.front(); que.pop();
		// cerr << "i: " << i << '\n';
		queue<pair<int, int>> q;
		q.push({i, 0});
		while (!q.empty()) {
			auto p = q.front(); q.pop();
			if (p.second == 3) {
				dist[p.first] = min(dist[p.first], dist[i] + 1);
				que.push(p.first);
				continue;
			}
			else {
				for (auto &c : g[p.first]) {
					if (vis[c][p.second + 1]) {
						// cerr << "vis " << c << ' ' << p.second + 1 << '\n';
						continue;
					}
					vis[c][p.second + 1] = true;
					q.push({c, p.second + 1});
				}
			}
		}
	}
	// FOR (i, 1, n) cout << dist[i] << ' ';
	// cout << '\n';
	if (dist[t] == INF) cout << -1;
	else cout << dist[t];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 1;
	while (t--) 
		solve();
	return 0;
}