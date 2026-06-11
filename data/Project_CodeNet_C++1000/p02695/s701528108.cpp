#include <bits/stdc++.h>

using namespace std;

int n, m, q;
int res, a[55], b[55], c[55], d[55], p[15];

void solve(int lv, int lt) {
	if (lv == n) {
		int tot = 0;
		for (int i = 0; i < q; i++) {
			if (p[b[i]] - p[a[i]] == c[i]) tot += d[i];
		}
		res = max(res, tot);
		return;
	}
	
	for (int i = lt; i <= m; i++) {
		p[lv] = i;
		solve(lv + 1, i);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
		a[i]--;
		b[i]--;
	}
	
	solve(0, 1);
	
	printf("%d\n", res);
}
