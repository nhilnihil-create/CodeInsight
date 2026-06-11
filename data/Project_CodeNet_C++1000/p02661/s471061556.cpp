#include <bits/stdc++.h>
using namespace std;
void read (int &x) {
	char ch = getchar(); int f = 0; x = 0;
	while (!isdigit(ch)) { if (ch == '-') f = 1; ch = getchar(); }
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); if (f) x = -x;
} const int N = 2e5 + 10;
int a[N], b[N];
signed main() {
	int n; scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) 
		scanf ("%d %d", a + i, b + i);
	sort (a + 1, a + n + 1); sort (b + 1, b + n + 1);
	if (n & 1) {
		int t = (n + 1) / 2;
		printf ("%d\n", b[t] - a[t] + 1);
	} else {
		int t = n / 2;
		printf ("%d\n", b[t] + b[t + 1] - a[t] - a[t + 1] + 1);
	} return 0;
}