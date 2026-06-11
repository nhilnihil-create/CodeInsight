#include <atcoder/fenwicktree>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
typedef long long ll;
int main() {
	int N, Q;
	cin >> N >> Q;
	fenwick_tree<ll> fw(N);
	for (int i = 0; i < N; ++ i) {
		int x;
		cin >> x;
		fw.add(i, x);
	}
	for (int i = 0; i < Q; ++ i) {
		int t;
		cin >> t;
		if (t == 0) {
			int p, x;
			cin >> p >> x;
			fw.add(p, x);
		} else {
			int l, r;
			cin >> l >> r;
			cout << fw.sum(l, r) << endl;
		}
	}
}
