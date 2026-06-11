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

const int N = 3005;
const int P = 998244353;
int f[N];

signed main()
{
	int n = read(), s = read();
	f[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		int x = read();
		for (int i = s; i >= 0; --i)
		{
			if (i + x <= s) (f[i + x] += f[i]) %= P;
			(f[i] *= 2) %= P;
		}
	}
	printf("%d\n", f[s]);
	
	return 0;
}
