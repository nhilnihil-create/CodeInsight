#include <bits/stdc++.h>

using namespace std;

long long n, u, v, ans = 0, mn, mx;

vector<pair<long long, long long>> adj;

void solve() {
	cin >> n;
	adj.resize(n + 1);
	for (long long i = 1; i < n; ++i) {
		cin >> u >> v;
		adj[i] = {u, v};
	}
	for (long long i = 1; i <= n; ++i) {
		ans += i * (n - i + 1);
	}
	for (long long i = 1; i < n; ++i) {
		mn = min(adj[i].first, adj[i].second), mx = max(adj[i].first, adj[i].second), ans -= mn * (n - mx + 1);
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
    //freopen("input.txt", "r", stdin);
	solve();
    return 0;
}