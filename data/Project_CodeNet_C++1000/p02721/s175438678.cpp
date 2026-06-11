#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

int n, k, c, d, pos;
int l[maxn], r[maxn];
char s[maxn];

signed main () {
	scanf("%d %d %d", &n, &k, &c);
	scanf("%s", &s);
	d = 1, pos = 0;
	while (d <= k && pos < n) {
		while (s[pos] == 'x' && pos < n) 
			++pos;
		l[d] = pos;
		pos += c + 1, ++d;
	}
	d = k, pos = n - 1;
	while (d && pos >= 0) {
		while (s[pos] == 'x' && pos >= 0)
			--pos;
		r[d] = pos;
		pos -= c + 1, --d;
	}
	for (int i = 1; i <= k; ++i) {
		if (l[i] == r[i])
			printf("%d\n", l[i] + 1);
	}
}
