#include <bits/stdc++.h>
#include <atcoder/dsu>

using namespace std;
using namespace atcoder;

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	dsu d(n);
	for (int i = 0; i < q; i++) {
		int t, u, v;
		scanf("%d %d %d", &t, &u, &v);
		if (t) {
			puts(d.same(u, v) ? "1" : "0");
		} else {
			d.merge(u, v);
		}
	}
	return 0;
}