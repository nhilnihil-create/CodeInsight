#include <bits/stdc++.h>
using namespace std;

long long sum, len;
int m;
long long c, d;

signed main () {
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%lld %lld", &d, &c);
		sum += c * d;
		len += c;
	}
	printf("%lld\n", len - 1 + (sum - 1) / 9);
}
