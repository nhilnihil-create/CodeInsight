#include <bits/stdc++.h>

typedef long long ll;

const int N = 105;

char s[N];
int k, n, tot, len[N];
ll ans;

int main()
{
	bool is = 1;
	scanf("%s%d", s + 1, &k); n = strlen(s + 1);
	for (int i = 1; i <= n; i++) if (s[i] != s[1]) is = 0;
	if (is) return std::cout << 1ll * n * k / 2 << std::endl, 0;
	for (int i = 1, c = 1; i <= n; i++)
		if (s[i] != s[i + 1]) len[++tot] = c, c = 1; else c++;
	if (s[1] != s[n])
	{
		for (int i = 1; i <= tot; i++) ans += len[i] >> 1;
		return std::cout << ans * k << std::endl, 0;
	}
	for (int i = 2; i < tot; i++) ans += len[i] >> 1; ans *= k;
	return std::cout << ans + 1ll * (k - 1) * (len[1] + len[tot] >> 1)
		+ (len[1] >> 1) + (len[tot] >> 1) << std::endl, 0;
}