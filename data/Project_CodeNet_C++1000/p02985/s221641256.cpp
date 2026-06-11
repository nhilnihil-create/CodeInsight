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

using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int N = 1e5 + 7; 

int add(int a, int b) {
	return (a + b) % MOD;
}

int mul(int a, int b) {
	return (a * b) % MOD;
}

int binpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mul(a, res);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int divv(int a, int b) {
	return mul(a, binpow(b, MOD - 2));
}

int k;
vector<int> g[N];

int ans = 1;

void dfs(int cur, int p) {
	int c = k - 2;
	if (p == -1) {
		c = k - 1;
	}
	for (auto t : g[cur]) {
		if (t != p) {
			ans = mul(ans, c);
			c--;
			dfs(t, cur);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n >> k;
	for (int i = 0; i + 1 < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, -1);
	ans = mul(k, ans);
	cout << ans << endl;
}
