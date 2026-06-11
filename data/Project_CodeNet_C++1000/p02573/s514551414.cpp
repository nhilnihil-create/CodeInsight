#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
	vector <int> r;

	UnionFind(int n) {
		r = vector<int>(n, -1);
	}

	int root(int x) {
		if(r[x] < 0) return x;
		return r[x] = root(r[x]);
	}

	bool Union(int x, int y) {
		x = root(x);
		y = root(y);
		if(x == y) return false;
		if(r[x] > r[y]) swap(x, y);
		r[x] += r[y];
		r[y] = x;
		return true;
	}

	int size(int x) {
		return -r[root(x)];
	}
};


int main() {
	int n, m;
	cin >> n >> m;

	UnionFind UF(n);
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a -= 1;
		b -= 1;
		UF.Union(a, b);
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans = max(ans, UF.size(i));
	}

	cout << ans << endl;
	return 0;
}