#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

template<typename T>
vector<T> dijkstra(int s, vector<vector<pair<int, T>>>& G) {
	const int n = G.size();
	vector<T> d(n, numeric_limits<T>::max());
	vector<int> b(n, -1);
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
	d[s] = 0;
	q.emplace(d[s], s);
	while (!q.empty()) {
		pair<T, int> p = q.top();
		q.pop();
		int v = p.second;
		if (d[v] < p.first) continue;
		for (auto& e : G[v]) {
			int u = e.first;
			T c = e.second;
			if (d[u] > d[v] + c) {
				d[u] = d[v] + c;
				b[u] = v;
				q.emplace(d[u], u);
			}
		}
	}
	return d;
}

int main() {
	int H, W; cin >> H >> W;
	vector<string> s(H);
	for (int i = 0; i < H; ++i)
		cin >> s[i];
	vector<vector<pair<int, int>>> g(H * W);
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			int idx = W * i + j;
			if (j < W - 1) { // 右へ
				int idx_right = idx + 1;
				if (s[i][j] == '.' && s[i][j + 1] == '#')
					g[idx].emplace_back(idx_right, 1);
				else g[idx].emplace_back(idx_right, 0);
			}
			if (i < H - 1) { // 下へ
				int idx_under = idx + W;
				if (s[i][j] == '.' && s[i + 1][j] == '#')
					g[idx].emplace_back(idx_under, 1);
				else g[idx].emplace_back(idx_under, 0);
			}
		}
	}
	int res = dijkstra<int>(0, g)[H * W - 1];
	if (s[0][0] == '#') ++res;
	cout << res << endl;
	return 0;
}