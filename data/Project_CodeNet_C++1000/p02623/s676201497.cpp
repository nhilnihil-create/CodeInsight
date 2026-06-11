#include "bits/stdc++.h"

typedef long long ll;
typedef long double ld;

/*
int %d
long long %lld
double %lf %0.6lf
long double %0.6Lf
char %c
string %s
*/

int main()
{
#if _MSC_VER
	freopen("input.txt", "r", stdin);
#endif
	ll k;
	int n, m;
	scanf("%d%d%lld", &n, &m, &k);
	std::vector<int> a(n);
	std::vector<ll> b(m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%lld", &b[i]);
		if (i)
		{
			b[i] += b[i - 1ll];
		}
	}
	int ans = std::upper_bound(b.begin(), b.end(), k) - b.begin();
	ll acum = 0;
	for (int i = 0; i < n; ++i)
	{
		acum += a[i];
		if (acum > k)
		{
			break;
		}
		int temp = std::upper_bound(b.begin(), b.end(), k - acum) - b.begin();
		ans = std::max(ans, i + 1 + temp);
	}
	printf("%d\n", ans);
	return 0;
}