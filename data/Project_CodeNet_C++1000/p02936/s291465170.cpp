#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
const int siz = 2 * 1e5 + 7;
vector<int>adj[siz];
vector<int>weight(siz);
int n, q;
void dfs(int node, int par) {
	for (auto k : adj[node]) {
		if (k == par)continue;
		weight[k] += weight[node];
		dfs(k, node);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 0; i < q; i++) {
		int node, val;
		cin >> node >> val;
		weight[node] += val;
	}
	dfs(1, -1);
	for (int i = 1; i <= n; i++) {
		cout << weight[i] << endl;
	}

}