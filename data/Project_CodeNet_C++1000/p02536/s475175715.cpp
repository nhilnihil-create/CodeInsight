#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <chrono>
#include <random>

using namespace std;

typedef long long ll;
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int ans = 0;
	vector<int> used(n);

	function<void(int)> dfs = [&](int v) {
		used[v] = 1;
		for (int to : g[v])
			if (!used[to])
				dfs(to);
	};

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			ans++;
			dfs(i);
		}
	}

	cout << ans - 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#if defined(_DEBUG)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int q = 1;
	//cin >> q;
	for (; q > 0; q--) {
		solve();
		//cout << endl;
	}
}