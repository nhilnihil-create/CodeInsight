#include <bits/stdc++.h>
using namespace std;

#define LL long long

int n;
LL ans;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) ans += 1ll * i * (n - i + 1);
	for(int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if(a > b) swap(a, b);
		ans -= 1ll * a * (n - b + 1);
	}
	printf("%lld\n", ans);
	return 0;
}
