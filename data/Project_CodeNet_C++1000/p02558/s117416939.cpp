#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
	int n; cin >> n;
	int q; cin >> q;
	dsu d(n);
	while(q--) {
		int t, u, v; cin >> t >> u >> v;
		if(t == 0) {
			d.merge(u, v);
		} else {
			cout << d.same(u, v) << '\n';
		}
	}
	return 0;
}