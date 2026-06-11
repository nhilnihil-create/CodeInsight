#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int sz = 2e5 + 1;

int n;
vector<int> g[sz];
ll ans = 0;

void dfs(int v, int pred) {
	for (int to : g[v]) {
		if (to ^ pred) {
			ll l = min(v, to) + 1;
			ll r = max(v, to) + 1;
			ans -= l * (n - r + 1);
			dfs(to, v);
		}
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (ll i = 1; i <= n; i++)
		ans += i * (n - i + 1);
	dfs(0, -1);
	cout << ans;
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
		cout << endl;
	}
}
