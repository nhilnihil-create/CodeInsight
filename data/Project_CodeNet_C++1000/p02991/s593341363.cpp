#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 100000;
const int INF = 1001001001;

int main() {
	int n, m;
	cin >> n >> m;
	function<int(int, int)> idx = [&](int x, int m) {
		return m % 3 * n + x;
	};
	vector<vector<int>> g(n*3);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		for (int j = 0; j < 3; j++) {
			g[idx(u, j)].push_back(idx(v, j+1));
		}
	}
	int s, t;
	cin >> s >> t;
	s--; t--;
	int d[MAX*3]; fill(d, d+MAX*3, INF);
	d[s] = 0;
	queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int v = que.front(); que.pop();
		for (int i : g[v]) {
			if (d[i] != INF) continue;
			d[i] = d[v] + 1;
			que.push(i);
		}
	}

	int ans = d[t]!=INF ? d[t] / 3 : -1;
	cout << ans << endl;
	return 0;
}