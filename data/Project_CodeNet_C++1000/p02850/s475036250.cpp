#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

// dfs（深さ優先探索）
// https://qiita.com/drken/items/4a7869c5e304883f539b

void dfs(vector<vector<pair<int, int>>> &g, vector<int> &c, int v, int p, int pc) {
	int now = 1;
	for(auto t: g[v]) {
		int nv = t.first;
		int nc = t.second;
		if(nv == p) continue;
		if (pc == now) now++;
		c[nc] = now;
		dfs(g, c, nv, v, now);
		now++;
	}
}

int main() {
	int n, k = 0;
	cin >> n;
	vector<vector<pair<int, int>>> g(n);
	vector<pair<int, int>> e(n-1);
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(make_pair(b, i));
		g[b].push_back(make_pair(a, i));
	}
	vector<int> c(n-1);
	dfs(g, c, 0, -1, 0);
	rep(i, n) {
		k = max(k, (int) g[i].size());
	}
	cout << k << endl;
	rep(i, n-1) cout << c[i] << endl;
	return 0;
}