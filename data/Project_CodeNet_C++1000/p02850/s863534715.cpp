#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1000000000;

int main() {
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].emplace_back(b, i);
		g[b].emplace_back(a, i);
	}

	int s = 0;
	int d[n];
	fill(d, d+n, INF);
	d[s] = 0;
	int prev_color[n];
	prev_color[s] = 0;
	int color[n];
	int max_color = 1;
	queue<int> que;
	que.push(s);
	while (!que.empty()) {
		int v = que.front(); que.pop();
		int ng_color = prev_color[v];
		int c = 1;
		for (auto e : g[v]) {
			if (d[e.first] == INF) {
				d[e.first] = d[v] + 1;
				if (c == ng_color) c++;
				color[e.second] = c;
				prev_color[e.first] = c;
				max_color = max(max_color, c);
				c++;
				que.push(e.first);
			}
		}
	}
	cout << max_color << endl;
	for (int i = 0; i < n-1; ++i) {
		cout << color[i] << endl;
	}
	return 0;
}