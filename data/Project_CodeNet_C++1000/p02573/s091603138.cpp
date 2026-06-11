#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

vector<int> parent;

int root(int x) {
	if (parent[x]==x) {
		return x;
	}
	else {
		return parent[x] = root(parent[x]);
	}
}

bool same(ll x, ll y) {
	return root(x) == root(y);
}

void unite(ll x, ll y) {
	x = root(x);
	y = root(y);
	if (x == y) return;

	parent[x] = y;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<ll> a(m);
	vector<ll> b(m);
	vector<ll> c(n+1,0);

	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
	}

	parent.resize(n+1);

	for (int i = 1; i <= n;i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m;i++) {
		unite(a[i], b[i]);
		for (int j = 1; j <= n; j++) {
		}
	}

	for (int i = 1; i <= n; i++) {
		c[root(i)]++;
	}

	ll result = 0;

	for (int i = 1; i <= n; i++) {
		result = max(result,c[i]);
	}

	cout << result << endl;

	return 0;
}
