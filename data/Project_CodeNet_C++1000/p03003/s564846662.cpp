#include <bits/stdc++.h>

using namespace std;
const int N = 2e3 + 3, MOD = 1e9 + 7;
int n, m, a[N], b[N], mem[N][N][3];
int go(int i, int j, int state) {
	if (i == n || j == m)
		return 0;
	int &ret = mem[i][j][state];
	if (~ret)
		return ret;
	ret = 0;
	if (state == 0) {
		ret = (go(i + 1, j, 0) + go(i, j, 1)) % MOD;
	} else if (state == 1) {
		ret = (go(i, j + 1, 1) + go(i, j, 2)) % MOD;
	} else if (a[i] == b[j]) {
		ret = (ret + go(i + 1, j + 1, 0) + 1) % MOD;
	}
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
//	freopen("input.in", "r", stdin);
#endif
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < m; ++i)
		scanf("%d", b + i);
	memset(mem, -1, sizeof mem);
	printf("%d\n", (go(0, 0, 0) + 1) % MOD);
	return 0;
}
