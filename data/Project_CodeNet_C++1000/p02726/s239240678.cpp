#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pi pair <int, int>

int n, x, y, dist[2100];
vector <int> G[2100];
queue <int> q;
map <int, int> mp;

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> x >> y;
	G[x].pb(y);
	G[y].pb(x);
	for(int i = 1; i < n; ++i) {
		G[i].pb(i + 1);
		G[i + 1].pb(i);
	}
	for(int k = 1; k < n; ++k) {
		mp[k] = 0;
	}
	// bfs
	for(int i = 1; i <= n; ++i) {
		memset(dist, -1, sizeof(dist));
		int source = i;
		q.push(source);
		dist[source] = 0;
		while (q.size()) {
			int u = q.front();
			q.pop();
			for(int j = 0; j < G[u].size(); ++j) {
				int v = G[u][j];
				if (dist[v] == -1) {
					q.push(v);
					dist[v] = dist[u] + 1;
					++mp[dist[v]];
				}
			}
		}
	}
	for(auto it:mp) {
		cout << it.second/2 << '\n';
	}
}