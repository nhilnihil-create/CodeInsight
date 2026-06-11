#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
	int n, q; cin >> n >> q;
	fenwick_tree<int64_t> ft(n);
	for(int i = 0; i < n; ++i) {
		int a; cin >> a;
		ft.add(i, a);
	}
	while(q--) {
		int t; cin >> t;
		if(t == 0) {
			int p, x; cin >> p >> x;
			ft.add(p, x);
		} else {
			int l, r; cin >> l >> r;
			cout << ft.sum(l, r) << '\n';
		}
	}
	return 0;
}