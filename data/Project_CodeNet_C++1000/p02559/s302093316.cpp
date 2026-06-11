#include <atcoder/fenwicktree>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main() {
	int n, q; cin >> n >> q;
	fenwick_tree<ll> fw(n);
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		fw.add(i, x);
	}
	for (int i = 0; i < q; ++i) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 0) fw.add(b, c);
		else cout << fw.sum(b, c) << endl;
	}
	return 0;
}