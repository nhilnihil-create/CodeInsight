#include <iostream>
#include <vector>
using namespace std;

using pll = pair<long, long>;
constexpr long MOD = 1000000007;

struct UnionFind {
	//自身が親であれば、その集合に属する頂点数に-1を掛けたもの
	//そうでなければ親のid
	vector<long> r;

	explicit UnionFind(long N) {
		r = vector<long>(N, -1);
	}

	long root(long x) {
		if (r[x] < 0) return x;
		return r[x] = root(r[x]);
	}

	bool unite(long x, long y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (r[x] > r[y]) swap(x, y);
		r[x] += r[y];
		r[y] = x;
		return true;
	}

	long size(long x) {
		return -r[root(x)];
	}
};

int main() {
	long n, m; cin >> n >> m;
	UnionFind UF(n);
	for (long i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		UF.unite(a, b);
	}

	long ans = 0;
	for (long i = 0; i < n; i++) {
		ans = max(ans, UF.size(i));
	}

	cout << ans << endl;
	return 0;
}
