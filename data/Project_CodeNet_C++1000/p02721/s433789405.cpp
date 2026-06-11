#include <cstdio>
const int N = 2e5 + 5;
int n, m, k;
char s[N];
int a1[N], a2[N], cnt1, cnt2;
int main () {
	scanf ("%d%d%d%s", &n, &m, &k, s + 1);
	for (int i = 1; i <= n; i ++) {
		if (s[i] == 'o') {
			a1[++ cnt1] = i;
			i += k;
		}
	}
	cnt2 = m;
	for (int i = n; i >= 1; i --) {
		if (s[i] == 'o') {
			a2[cnt2 --] = i;
			i -= k;
			if (cnt2 == 0) break;
		}
	}
	for (int i = 1; i <= m; i ++)
		if (a1[i] == a2[i]) printf("%d\n", a1[i]);
}