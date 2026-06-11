#include<bits/stdc++.h>

#define LL long long
#define RG register

using namespace std;
template<class T> inline void read(T &x) {
	x = 0; RG char c = getchar(); bool f = 0;
	while (c != '-' && (c < '0' || c > '9')) c = getchar(); if (c == '-') c = getchar(), f = 1;
	while (c >= '0' && c <= '9') x = x*10+c-48, c = getchar();
	x = f ? -x : x;
	return ;
}
template<class T> inline void write(T x) {
	if (!x) {putchar(48);return ;}
	if (x < 0) x = -x, putchar('-');
	int len = -1, z[20]; while (x > 0) z[++len] = x%10, x /= 10;
	for (RG int i = len; i >= 0; i--) putchar(z[i]+48);return ;
}
const int N = 3e5 + 10;
int a[N], n, m, s[N], b[N];
bool check(int x, int k) {
	int p = lower_bound(a + 1, a + 1 + m, x) - a;
	return s[p - 1] / x + m - p + 1 >= k;
}
int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) read(b[i]);
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n; i++)
		if (b[i] != b[i - 1]) a[++m] = 1;
		else a[m]++;
	sort(a + 1, a + 1 + m);
	for (int i = 1; i <= m; i++) s[i] = s[i - 1] + a[i];
	for (int k = 1; k <= n; k++) {
		int l = 1, r = s[m] / k;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid, k)) l = mid + 1;
			else r = mid - 1;
		}
		printf("%d\n", l - 1);
	}
	return 0;
}
