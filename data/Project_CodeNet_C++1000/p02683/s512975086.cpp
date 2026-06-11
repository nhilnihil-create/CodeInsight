#include <iostream>
#include <cstdio>
#define N 15
using namespace std;

int M = 2e9;
int n, m, X, mn = 2e9, w[N], a[N][N], s[N];
void f(int p, int q) {
	int i;
	if (q >= mn) return;
	if (p == n) {
		for (i = 0; i < m; i++) {
			if (s[i] < X) break;
		}
		if (i == m) {
			mn = q;
		}
		return;
	}
	f(p + 1, q);
	for (i =0; i < m; i++) {
		s[i] += a[p][i];
	}
	f(p + 1, q + w[p]);
	for (i =0; i < m; i++) {
		s[i] -= a[p][i];
	}
}

int main()
{
	int i, j;
	cin >> n >> m >> X;
	for (i = 0; i < n; i++) {
		scanf ("%d", &w[i]);
		for (j = 0; j < m; j++) {
			scanf ("%d", &a[i][j]);
		}
	}
	mn = M;
	f(0, 0);
	if (mn == M) cout << -1 << endl;
	else cout << mn << endl;
    return 0;
}
