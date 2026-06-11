#include <atcoder/fenwicktree>
#include <bits/stdc++.h>
using namespace atcoder;
using namespace std;

typedef long long ll;

int main()
{
	int n, q, c, a, b;
	scanf("%d%d", &n, &q);
	fenwick_tree<ll> fw(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		fw.add(i, a);
	}
	while (q--) {
		scanf("%d%d%d", &c, &a, &b);
		if (c) {
			printf("%lld\n", fw.sum(a, b));
		}
		else {
			fw.add(a, b);
		}
	}
}