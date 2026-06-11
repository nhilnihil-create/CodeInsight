#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100005;

int n, m, v, p, a[maxn];
ll sum[maxn];

int check(int x)
{
	if (a[x] + m < a[p]) return 0;
	return (ll)(a[x] + m) * (x - p) - (sum[x - 1] - sum[p - 1]) >= (ll)m * (v - (p - 1) - (n - x + 1));
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &v, &p);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];

	int l = p, r = n, mid;
	while (l < r) {
		mid = (l + r + 1) >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}

	printf("%d\n", l);
	
	return 0;
}
