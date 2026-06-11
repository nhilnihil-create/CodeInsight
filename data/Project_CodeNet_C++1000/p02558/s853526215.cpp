#include <atcoder/dsu>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;

int main()
{
	int n, q, c, u, v;
	scanf("%d%d", &n, &q);
	dsu d(n);
	while (q--) {
		scanf("%d%d%d", &c, &u, &v);
		if (c) {
			printf("%d\n", d.same(u, v));
		}
		else {
			d.merge(u, v);
		}
	}
}