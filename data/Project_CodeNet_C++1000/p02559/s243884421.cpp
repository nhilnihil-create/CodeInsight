#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct fenwicktree {
	int n;
	vector<ll> a, t;
	fenwicktree(int N) {
		n = N;
		a.clear(); t.clear();
		a.resize(N + 1 , 0);
		t.resize(N + 1, 0);
	}
public:
	void update(int x, int val) { //val is added to the xth
		x++;
		while (x <= n) {t[x] += 1ll * val; x += (x & -x);}
	}
	ll query(int x) {
		x++;
		ll sum = 0;
		while (x > 0) {sum += 1ll * t[x]; x -= (x & -x);}
		return sum;
	}
	ll sum(int l, int r) {
		return query(r) - query(l - 1);
	}
};

void solve() {
	int n, q; cin >> n >> q;
	fenwicktree ans(n);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		ans.update(i, 1ll * a);
	}
	while (q--) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 0)ans.update(a, 1ll * b);
		else cout << ans.sum(a, b - 1) << endl;
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
