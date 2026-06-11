#include <bits/stdc++.h>
using namespace std;
inline void read (int &x) {
	char ch = getchar(); x = 0;
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
} const int N = 5010;
int n, q, d[N], a[N];
signed main() {
	read (n), read (q);
	for (int i = 0; i < n; ++i) read (a[i]);
	while (q--) {
		int k, x, m, cnt = 0; long long sum = 0;
		read (k), read (x), read (m);
		for (int i = 0; i < n; ++i) d[i] = a[i] % m, sum += d[i];
		for (int i = 0; i < n; ++i) {
			if (!d[i]) cnt += (k - 1) / n + (i < (k - 1) % n);
		} sum = (k - 1) / n * sum + x; 
		for (int i = 0; i < (k - 1) % n; ++i) sum += d[i];
		printf ("%d\n", k - 1 - sum / m + x / m - cnt);
	} return 0;
}