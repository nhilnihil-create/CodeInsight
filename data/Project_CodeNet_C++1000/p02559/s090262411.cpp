#include <bits/stdc++.h>
#include <atcoder/fenwicktree>

using namespace std;
using namespace atcoder;

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	fenwick_tree<long long> fenw(n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		fenw.add(i, x);
	}
	for (int i = 0; i < q; i++) {
		int t, u, v;
		scanf("%d %d %d", &t, &u, &v);
		if (t) {
			printf("%lld\n", fenw.sum(u, v));
		} else {
			fenw.add(u, v);
		}
	}
	return 0;
}