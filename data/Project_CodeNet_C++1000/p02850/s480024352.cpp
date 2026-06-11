#include "bits/stdc++.h"
using namespace std;
vector<int>Col(100005);
struct Edge {
	int to, id;
	Edge(int to, int id) :to(to), id(id) {}
};
vector<Edge>g[100005];

void dfs(int v, int d = 0, int p = -1) {
	int num = 1;
	for (Edge e : g[v]) {
		if (p == e.to) {
			continue;
		}
		if (num == d) {
			num++;
		}
		Col[e.id] = num;
		dfs(e.to, num, v);
		num++;
	}
}

int main() {
	int N;
	cin >> N;
	for (int n = 0; n < N - 1; ++n) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].emplace_back(b, n);
		g[b].emplace_back(a, n);
	}
	int color = 0;
	int sta;
	for (int n = 0;n < N; ++n) {
		color = max(color, (int)g[n].size());
		if (color == (int)g[n].size()) {
			sta = n;
		}
	}
	cout << color <<endl;
	dfs(sta);
	for (int n = 0; n < N - 1; ++n) {
		cout << Col[n] << endl;
	}
	return 0;
}