#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb emplace_back
typedef pair<int,int> pi;

int n, x, y, ans[2005], dist[2005];
vector<int> g[2005];

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cin >> n >> x >> y;
	for (int i = 1; i <= n; ++i) {
		g[i].pb(i + 1);
		g[i + 1].pb(i);
	}
	g[x].pb(y);
	g[y].pb(x);
	for (int i = 1; i <= n; ++i) {
		queue<int> q;
		memset(dist, -1, sizeof dist);
		dist[i] = 0;
		q.emplace(i);
		while (q.size()) {
			int x = q.front();
			q.pop();
			for (auto v: g[x]) {
				if (dist[v] != -1) continue;
				dist[v] = dist[x] + 1;
				q.emplace(v);
			}
		}
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			++ans[dist[j]];
		}
	}
	for (int i = 1; i < n; ++i) cout << ans[i] / 2 << '\n';
	return 0;
}
