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

const int N = 305;
int h[N], f[N][N];

signed main()
{
	int n = read();
	int k = read();
	for (int i = 1; i <= n; ++i) h[i] = read();
	
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; ++i) f[i][1] = h[i];
	for (int i = 2; i <= n; ++i)
		for (int j = 2; j <= i; ++j)
			for (int p = 1; p < i; ++p)
				f[i][j] = min(f[i][j], f[p][j - 1] 
					+ max(0LL, h[i] - h[p]));
	
	int ans = f[0][0];
	for (int i = n - k; i <= n; ++i) ans = min(ans, f[i][n - k]);
	if (k == n) puts("0"); else printf("%lld\n", ans);
	return 0;
}
