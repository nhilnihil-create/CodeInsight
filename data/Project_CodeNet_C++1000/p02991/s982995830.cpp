#include<bits/stdc++.h>
using namespace std;
#define int long long
struct vl {
	int u, step;
};
const int MAXN = 1e5 + 69;
int n, m;
int s, t;
vector<int> a[MAXN];
int check[MAXN][3];
void bfs(vl u) {
	queue<vl> q;
	check[u.u][u.step] = 1;
	q.push(u);
	while (!q.empty()) {
		vl u = q.front(); q.pop();
		for (int v : a[u.u]) {
			int nstep = (u.step + 1) % 3;
			if (check[v][nstep]) continue;
			check[v][nstep] = check[u.u][u.step] + 1;
			q.push({v, nstep});
		}
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		a[u].push_back(v);
	}
	cin >> s >> t;
	bfs({s, 0});
	if (!check[t][0]) cout << -1;
	else cout << (check[t][0] - 1) / 3;
}