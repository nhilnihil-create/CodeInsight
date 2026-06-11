#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, k, a[N], b[N];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	while (k--) {
		for (int i = 1; i <= n; i++) b[i] = 0;
		for (int i = 1; i <= n; i++) {
			b[max(1, i - a[i])]++;
			if (i + a[i] <= n - 1) b[i + a[i] + 1]--;
		}
		for (int i = 1; i <= n; i++) b[i] += b[i - 1], a[i] = b[i];
		int flag = 1;
		for (int i = 1; i <= n; i++) {
			if (a[i] != n) {
				flag = 0;
				break;
			}
		}
		if (flag) break;
	}
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}