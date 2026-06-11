#include<cstdio>
using namespace std;

#define int long long

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

const int N = 1e5 + 5;
int a[N], p[64];

void insert(int x)
{
	for (int i = 60; i >= 0; --i) if (x >> i)
	{
		if (p[i]) x ^= p[i];
		else { p[i] = x; break; }
	}
}

signed main()
{
	int n = read(), sum = 0, ans = 0;
	for (int i = 1; i <= n; ++i) sum ^= (a[i] = read());
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= 60; ++j)
			if ((sum >> j & 1) && (a[i] >> j & 1))
				a[i] -= (1LL << j);
	
	for (int i = 1; i <= n; ++i) insert(a[i]);
	for (int i = 60; i >= 0; --i) 
		if ((ans ^ p[i]) > ans) ans ^= p[i];
	
	printf("%lld\n", ans + (sum ^ ans));
	
	return 0;
}
