#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 10;

int n, m;
int a[maxN + 1], b[maxN + 1];

int main()
{
	scanf("%d %d", &n, &m);
	m = min(m, 50);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

	while(m --)
	{
		for(int i = 0; i <= n; i++) b[i] = 0;
		for(int i = 1; i <= n; i++)
			b[ max(1, i - a[i]) ] ++, b[ min(n, i + a[i]) + 1 ] --;
		for(int i = 1; i <= n; i++) a[i] = a[i - 1] + b[i];
	}

	for(int i = 1; i <= n; i++) printf("%d ", a[i]);
	puts("");
	return 0;
}
