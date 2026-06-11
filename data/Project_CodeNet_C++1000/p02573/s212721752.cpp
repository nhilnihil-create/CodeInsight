#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> a[200500];
int used[200500];
int n, m;
int c = 0;
void dfs(int i) {
	used[i] = 1;
	c++;
	for (auto f : a[i]) {
		if (used[f] == 0) dfs(f);
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int k = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i].empty()) k++;
	}
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		if (used[i] == 0) {
			c = 0;
			dfs(i);
			mx = max(mx, c);
		}
	}
	cout << mx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}