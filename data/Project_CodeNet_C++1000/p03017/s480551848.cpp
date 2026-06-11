#include <bits/stdc++.h>

const int N = 2e5 + 5;

int n, a, b, c, d;
char s[N];

int main()
{
	scanf("%d%d%d%d%d%s", &n, &a, &b, &c, &d, s + 1);
	for (int i = a; i < c; i++) if (s[i] == '#' && s[i + 1] == '#')
		return puts("No"), 0;
	for (int i = b; i < d; i++) if (s[i] == '#' && s[i + 1] == '#')
		return puts("No"), 0;
	if (c < d) return puts("Yes"), 0;
	for (int i = b; i <= d; i++) if (s[i] == '.' && s[i - 1] == '.' && s[i + 1] == '.')
		return puts("Yes"), 0;
	return puts("No"), 0;
}