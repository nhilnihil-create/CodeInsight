#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

const int N = 2e5 + 5;
int a[N], b[N];

signed main()
{
	int n = read();
	for (int i = 1; i <= n; ++i) a[i] = read(), b[i] = read();
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	if (n % 2 == 0)
	{
		int c = a[n / 2] + a[n / 2 + 1];
		int d = b[n / 2] + b[n / 2 + 1];
		printf("%lld\n", d - c + 1);
	}
	else
	{
		int c = a[n / 2 + 1];
		int d = b[n / 2 + 1];
		printf("%lld\n", d - c + 1);
	}
	return 0;
}
