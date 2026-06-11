#include <cstdio>
#include <algorithm>

int n, k, a[200005], b[200005];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	while (k--) {
		for (int i = 1; i <= n; ++i) {
			b[i] = 0;
		}
		for (int i = 1; i <= n; ++i) {
			int l = i - a[i], r = i + a[i] + 1;
			l = std::max(l, 1), r = std::min(r, n + 1);
			++b[l], --b[r];
		}
		for (int i = 1; i <= n; ++i) {
			b[i] += b[i - 1];
		}
		bool flag = 1;
		for (int i = 1; i <= n; ++i) {
			a[i] = b[i];
			flag &= a[i] == n;
		}
		if (flag) {
			break;
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", a[i]);
	}
	putchar('\n');
}