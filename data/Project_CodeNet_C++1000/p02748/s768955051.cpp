//%std
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int out = 0, fh = 1;
	char jp = getchar();
	while ((jp > '9' || jp < '0') && jp != '-')
		jp = getchar();
	if (jp == '-')
		fh = -1, jp = getchar();
	while (jp >= '0' && jp <= '9')
		out = out * 10 + jp - '0', jp = getchar();
	return out * fh;
}
const int N = 1e5 + 10, inf = 1e9;
int n, m, a[N], b[N], k;
int main()
{
	int ma = inf, mb = inf;
	n = read(), m = read(), k = read();
	for (int i = 1; i <= n; ++i)
		ma = min(ma, a[i] = read());
	for (int i = 1; i <= m; ++i)
		mb = min(mb, b[i] = read());
	int ans = ma + mb;
	for (int i = 1; i <= k; ++i)
	{
		int x = read(), y = read();
		ans = min(ans, a[x] + b[y] - read()); 
	}
	printf("%d\n", ans);
	return 0;
}
