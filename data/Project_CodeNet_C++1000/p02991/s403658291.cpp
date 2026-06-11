#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

const int INF = 1e6 + 239;

int n;
vector<vector<int>> g;
vector<int> d;

void bfs(int s) {
	d.resize(3 * n, INF);
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto t : g[v]) {
			if (d[t] > d[v] + 1) {
				d[t] = d[v] + 1;
				q.push(t);
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m;
	cin >> n >> m;
	// n *= 3;
	g.resize(n * 3);
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		for (int fm = 0; fm < 3; fm++) {
			int sm = (fm + 1) % 3;
			g[u + n * fm].push_back(v + n * sm);
			// g[v + n * fm].push_back(u + n * sm);
		}
	}
	int s, t;
	cin >> s >> t;
	s--;
	t--;
	bfs(s);
	if (d[t] == INF) cout << -1 << endl;
	else cout << d[t] / 3 << endl;
}
