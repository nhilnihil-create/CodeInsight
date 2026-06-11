#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long LL;
const int N = 2020;
struct node {
	LL p, v;
}a[N];

LL f[N][N]; //dp[i][j] i表示移左边数量 j表示移右边数量

bool cmp(node x, node y) {
	return x.v > y.v;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].v;
		a[i].p = i;
	}
	sort(a, a + n, cmp);

	for (int i = 0; i < n; i++) {
		for (int j = 0; i + j < n; j++) {
			int t = i + j;
			f[i + 1][j] = max(f[i + 1][j], f[i][j] + abs(a[t].p - i) * a[t].v);
			f[i][j + 1] = max(f[i][j + 1], f[i][j] + abs(a[t].p - (n - 1 - j)) * a[t].v);
		}
	}

	LL res = 0;
	for (int i = 0; i <= n; i++) res = max(res, f[i][n - i]);
	cout << res << endl;

	return 0;
}