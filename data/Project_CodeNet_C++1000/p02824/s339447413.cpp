#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,v,p,a[100005],sum[100005];

signed main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&v,&p);
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = p;
	for (int i = 1; i <= n - p; i++)
	{
		if (a[i] + m < a[n - p + 1]) continue;
		int tmp = m * v - i * m - (p - 1) * m - (a[i] + m) * (n - p + 1 - i) + (sum[n - p + 1] - sum[i]);
		if (tmp <= 0) ans++;
	}
	printf("%lld\n",ans);
	return 0;
}