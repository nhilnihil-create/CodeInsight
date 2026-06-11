#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

vector<int> parent;
vector<int> rnk;
int Find(int i) {
	if (i == parent[i])
		return i;
	return parent[i] = Find(parent[i]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b)
		return;
	else {
		if (rnk[a] > rnk[b]) {
			parent[b] = a;
			rnk[a] += rnk[b];
		} else {
			parent[a] = b;
			rnk[b] += rnk[a];
		}
	}
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	int n, m;
	cin >> n >> m;
	parent.resize(n + 1);
	rnk.resize(n + 1, 1);
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		Union(a, b);
	}
	int max_size = 0;
	for (int i = 1; i <= n; i++)
		max_size = max(max_size, rnk[i]);
	cout << max_size;
	return 0;
}