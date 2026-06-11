#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct UnionFind
{
	std::vector<int> par, cou;
	UnionFind(int N = 0) : par(N), cou(N, 1) {
		iota(par.begin(), par.end(), 0);
	}
	int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		if (cou[x] < cou[y]) std::swap(x, y);
		par[y] = x, cou[x] += cou[y];
		return true;
	}
	int count(int x) { return cou[find(x)]; }
	bool same(int x, int y) { return find(x) == find(y); }
};

void solve() {
	int n; cin >> n;
	int q; cin >> q;
	UnionFind u(n);
	while (q--) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 0)u.unite(a, b);
		else if (t == 1) {
			if (u.same(a, b))cout << 1 << "\n";
			else cout << 0 << '\n';
		}
	}


}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// int t; cin >> t;
	// while (t--)
	solve();

}
