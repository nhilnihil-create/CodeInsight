#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ff first
#define ss second
#define endl '\n'

int k;
const ll MOD = 1e9 + 7;

const int MAX = 1e5;
vector<int> adj[MAX];
bool visited[MAX];

ll dfs (int root, bool is_child_of_root) {
	visited[root] = 1;
	ll ans = 1, factor = k - 2ll + is_child_of_root;

	for (int child : adj[root]) {
		if (!visited[child]) {
			ans = (ans * factor--) % MOD;
			ans = (ans * dfs(child, 0)) % MOD;
		}
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n >> k;

	for (int i = 0, u, v; i < n-1; ++i) {
		cin >> u >> v; --u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int root = 0; root < n; ++root) {
		if (adj[root].size() >= k) {
			cout << 0 << endl;
			return 0;
		}
	}

	ll ans = (k * dfs(0, 1)) % MOD;
	cout << ans << endl;

	return 0;
}