#include <bits/stdc++.h>

typedef long long ll;
const int maxn = 2e5 + 3, mo = 1e9 + 7;
int n, frac[maxn];
char s[maxn];

int main() {
	frac[0] = 1;
	for(int i = 1; i < maxn; ++i)
		frac[i] = frac[i - 1] * (ll)i % mo;
	scanf("%d%s", &n, s);
	int l = 0, ans = 1;
	for(int i = 0; i < 2 * n; ++i) {
		if((s[i] == 'B') ^ (l & 1)) {
			++l;
		} else {
			ans = ans * (ll)l % mo;
			--l;
		}
		if(l < 0) {
			puts("0");
			return 0;
		}
	}
	if(l) {
		puts("0");
		return 0;
	}
	printf("%lld\n", ans * (ll)frac[n] % mo);
	return 0;
}
