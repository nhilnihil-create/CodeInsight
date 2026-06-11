#include "bits/stdc++.h"
using namespace std;
#define fst first
#define scd second
int a[10][10];
signed main()
{
	int n, ans = 0, ans2 = 0;
	scanf("%d", &n);
	for(int i = 1, j = 1; i <= n; ++i)
	{
		if(i == j * 10)
		{
			j *= 10;
		}
		ans += a[i % 10][i / j];
		++a[i / j][i % 10];
		ans2 += i / j == i % 10;
	}
	printf("%d\n", ans * 2 + ans2);
}
