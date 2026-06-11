#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
const ll mod = 1e9 + 7;
const int N = 1e5 + 7;


ll mul(ll a, ll b) {
	return (a*b)%mod;
}
vector<int> conn[N];
int parent[N];
bool vis[N];
int coloring[N];

void bfs(int root) {
	memset(vis, 0, sizeof vis);
	queue<int> q;
	q.push(root);
	parent[root] = -1;
	vis[root] = 1;
	while(q.size()) {
		int node = q.front();
		q.pop();
		for (auto i : conn[node]) {
			if (vis[i])
				continue;
			q.push(i);
			parent[i] = node;
			vis[i] = 1;
		}
	}
}

void color(int root, int k) {
	memset(vis, 0, sizeof vis);
	queue<int> q;
	q.push(root);
	coloring[root] = k;
	vis[root] = 1;
	while(q.size()) {
		int node = q.front();
		q.pop();
		int siblings = 0;
		bool pp = parent[node] != -1;
		for (auto i : conn[node]) {
			if (vis[i])
				continue;

			q.push(i);
			coloring[i] = k - (siblings+1+pp);
			siblings++;
			vis[i] = 1;
		}
	}
}


int main() {
	fastIO;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		conn[u].push_back(v);
		conn[v].push_back(u);
	}
	bfs(1);
	memset(coloring, -1, sizeof coloring);
	color(1, k);
	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = mul(ans, coloring[i]);
	}
	cout << ans;
}
