#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct segment_tree {
	int n;
	vector<ll> tree, mod;

	inline void resize(int n_) {
		n = n_;
		tree.resize(4 * n);
		mod.resize(4 * n);
	}

	inline void push(int v, int vl, int vr) {
		if (!mod[v]) {
			return;
		}
		tree[v] += (ll)(vr - vl) * mod[v];
		if (vr - vl > 1) {
			mod[2 * v + 1] += mod[v];
			mod[2 * v + 2] += mod[v];
		}
		mod[v] = 0;
	}

	inline void update(int L, int R, int del) {
		update(0, 0, n, L, R, del);
	}

	void update(int v, int vl, int vr, int L, int R, int del) {
		push(v, vl, vr);
		if (R <= vl || vr <= L) {
			return;
		}
		if (L <= vl && vr <= R) {
			mod[v] += del;
			return;
		}
		int vm = (vl + vr) / 2;
		update(2 * v + 1, vl, vm, L, R, del);
		update(2 * v + 2, vm, vr, L, R, del);
		push(2 * v + 1, vl, vm);
		push(2 * v + 2, vm, vr);
		tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
	}

	inline ll get(int L, int R) {
		return get(0, 0, n, L, R);
	}

	ll get(int v, int vl, int vr, int L, int R) {
		push(v, vl, vr);
		if (R <= vl || vr <= L) {
			return 0;
		}
		if (L <= vl && vr <= R) {
			return tree[v];
		}
		int vm = (vl + vr) / 2;
		return get(2 * v + 1, vl, vm, L, R) + get(2 * v + 2, vm, vr, L, R);
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	vector<int> deg(n, 0);
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		if (v > u) {
			swap(v, u);
		}
		g[v].push_back(u);
		deg[u]++;
	}
	segment_tree tree;
	tree.resize(n);
	for (int i = 0; i < n; i++) {
		tree.update(i, n, deg[i]);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (ll)(n - i) * (n - i + 1) / 2;
		ans -= tree.get(i, n);
		for (auto v : g[i]) {
			tree.update(v, n, -1);
		}
	}
	cout << ans;
}