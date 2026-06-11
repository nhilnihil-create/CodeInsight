#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int maxn = 85;
int n, a[maxn];
LL m;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	m = 1000;
	for(int i = 1; i < n; ++i)
	{
		if(a[i] < a[i + 1]) m += (LL)(a[i + 1] - a[i]) * (m / a[i]);
	}
	printf("%lld", m);
	return 0;
}