#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

const int N = 1e5 + 5;

int n, a[N], b[N], tot;

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	std::sort(a + 1, a + n + 1);
	if (n % 3) return puts(a[1] == 0 && a[n] == 0 ? "Yes" : "No"), 0;
	for (int i = 1; i <= n / 3; i++)
		b[++tot] = a[i], b[++tot] = a[i + n / 3], b[++tot] = a[i + 2 * n / 3];
	b[n + 1] = b[1]; b[n + 2] = b[2];
	for (int i = 1; i <= n; i++) if (b[i] ^ b[i + 1] ^ b[i + 2])
		return puts("No"), 0;
	return puts("Yes"), 0;
}