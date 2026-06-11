#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define N 100005

int n, p, a[N];

ll m, v;

bool cmp(int x, int y)
{
	return x > y;
}

bool check(int x)
{
	if(x <= p) return 1;
	if(a[x] + m < a[p]) return 0;
	int rv = v - (p - 1) - (n - x + 1);
	if(rv < 0) return 1;
	ll rs = 1ll * rv * m;
	for(int i = p; i <= x - 1; i++)
		rs -= a[x] + m - a[i];
	return (rs <= 0);
}

int main()
{
	scanf("%d%lld%lld%d", &n, &m, &v, &p);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, cmp);
	int l = 1, r = n, ans = 0;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}