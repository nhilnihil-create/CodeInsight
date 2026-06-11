#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 200010, M = 1010;

int n;
int a[N], f[N];
LL m;

bool check(LL x)
{
	LL cnt = 0;
	for (int i = 1; i <= n; i ++ )
		if ((LL)a[i] * f[i] > x)
			cnt += max(0LL, (LL)a[i] - x / (LL)f[i]);
	return cnt <= m;
}

int main()
{
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &f[i]);
	sort(a + 1, a + 1 + n);
	sort(f + 1, f + 1 + n, greater<int>());
	
	LL l = 0, r = 1e12 + 10;
	while (l < r)
	{
		LL mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1LL;
	}
	
	printf("%lld\n", r);
	return 0;
}