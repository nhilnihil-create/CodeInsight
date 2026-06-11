#include <bits/stdc++.h>

const int N = 1e5 + 5;

int n, L = 1, tot, a[N];
bool vis[N];

int main()
{
	std::cin >> n; if (n == 1) return puts("No"), 0;
	while ((L << 1) <= n + 1) L <<= 1;
	if (L == n) return puts("No"), 0;
	puts("Yes");
	for (int i = 1; i < L; i <<= 1) vis[a[++tot] = i] = 1;
	for (int i = 1; i < L; i++) if (!vis[i]) a[++tot] = i;
	for (int i = 1; i < tot; i++) printf("%d %d\n", a[i], a[i + 1]);
	printf("%d %d\n", a[tot], a[1] + n);
	for (int i = 1; i < tot; i++) printf("%d %d\n", a[i] + n, a[i + 1] + n);
	for (int i = L; i < n; i += 2)
		printf("%d %d\n%d %d\n%d %d\n%d %d\n",
			i, n + 1, i + 1, i, 1, i + 1 + n, i + 1 + n, i + n);
	if (!(n & 1)) printf("%d %d\n%d %d\n",
		n, n * 2 - 1, n & -n, n * 2);
	return 0;
}