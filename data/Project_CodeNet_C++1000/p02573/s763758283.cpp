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

const int N = 2e5 + 7;

int used[N];
vector<int> g[N];

void dfs(int cur, int &c) {
	c++;
	used[cur] = 1;
	for (auto t : g[cur]) {
		if (!used[t]) {
			dfs(t, c);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			int c = 0;
			dfs(i, c);
			ans = max(ans, c);
		}
	}
	cout << ans << '\n';
}