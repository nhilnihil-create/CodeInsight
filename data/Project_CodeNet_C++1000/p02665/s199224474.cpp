#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n;
int a[1 << 17];
ll tot[1 << 17];

void prt(__int128 x) {
	if (x >= 10) prt(x / 10);
	putchar(x % 10 + '0');
}

int main() {
	scanf("%d", &n);
	rep(i, n + 1) scanf("%d", &a[i]);
	for (int i = n; i; -- i) tot[i] = tot[i + 1] + a[i];
	tot[0] = 1;
	rep(i, n + 1) if (i) {
		if (tot[i - 1] < a[i - 1]) { puts("-1"); return 0; }
		tot[i] = min(tot[i], (tot[i - 1] - a[i - 1]) * 2);
	}
	if (tot[n] < a[n]) { puts("-1"); return 0; }
	__int128 ans = 0;
	rep(i, n + 1) ans += tot[i];
	prt(ans); puts("");
	return 0;
}
