#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
using namespace std;

int n, q;
long long a[500010];

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		int x; scanf("%d", &x);
		for (int j = i; j <= n; j += lowbit(j))
			a[j] += x;
	}
	while (q--) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if (t) {
			long long sum = 0;
			for (int i = y; i > 0; i -= lowbit(i))
				sum += a[i];
			for (int i = x; i > 0; i -= lowbit(i))
				sum -= a[i];
			printf("%lld\n", sum);
		}
		else
			for (int i = x + 1; i <= n; i += lowbit(i))
				a[i] += y;
	}
	return 0;
}

