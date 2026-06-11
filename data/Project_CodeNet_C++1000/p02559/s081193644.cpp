#include "bits/stdc++.h"
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define ll long long

signed main() {
	int N, Q; cin >> N >> Q;
	fenwick_tree<long long>fw(N);
	for (int i = 0; i < N; i++) {
		long long a; cin >> a;
		fw.add(i, a);
	}
	for (int _ = 0; _ < Q; _++) {
		int t; cin >> t;
		if (t == 0) {
			int p; long long x; cin >> p >> x;
			fw.add(p, x);
		}
		else {
			int l, r; cin >> l >> r;
			cout << fw.sum(l, r) << endl;
		}
	}
	return 0;
}
