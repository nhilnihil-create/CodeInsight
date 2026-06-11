#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n; ll a[200010], ans;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]), a[i] += a[i - 1];
	ans = abs(a[n] - 2ll * a[1]);
	for(int i = 2; i < n; ++i)
		ans = min(ans, abs(a[n] - 2ll * a[i]));
	printf("%lld\n", ans);
	return 0;
}