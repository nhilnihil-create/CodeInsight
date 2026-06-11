#include <bits/stdc++.h>

typedef long long int64;

const int MAX_N = 110;

int n, k, m, len[MAX_N];
char s[MAX_N], t[MAX_N];

int main() {
	scanf("%s%d", s + 1, &k);
	n = strlen(s + 1);

	int64 ans = 0LL;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == t[m]) {
			++len[m];
		} else {
			t[++m] = s[i];
			len[m] = 1;
		}
	}
	
	if (m == 1)
		ans = 1LL * n * k / 2;
	else if (t[m] == t[1]) {
		ans = len[1] / 2 + len[m] / 2;
		ans += 1LL * (len[1] + len[m]) / 2 * (k - 1);
		for (int i = 2; i < m; ++i) {
			ans += 1LL * len[i] / 2 * k;
		}
	} else {
		for (int i = 1; i <= m; ++i) {
			ans += 1LL * len[i] / 2 * k;
		}
	}
	
	std::cout << ans << std::endl;
}