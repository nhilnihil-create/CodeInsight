#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

const int N = 3e5 + 5;
int a[N], cnt[N], ans[N];

int main()
{
	int n = read();
	for (int i = 1, x; i <= n; ++i) 
		x = read(), ++a[x], ++cnt[a[x]];
	for (int i = 1; i <= n; ++i) cnt[i] += cnt[i - 1];
	
	for (int i = n, j = 1; i >= 1; --i)
	{
		while (j <= n && cnt[j] >= 1LL * i * j) ++j;
		ans[i] = j - 1; 
	}
	for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
	
	return 0;
}
