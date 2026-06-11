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
LL m;
LL a[N], b[N];

bool check(LL x)
{
	LL cnt = 0;
	for (int i = 0; i < n; i ++ )
		if (a[i] * b[i] > x)
			cnt += a[i] - x / b[i];
	return cnt <= m;
}

int main()
{
	scanf("%d%lld", &n, &m);
	for (int i = 0; i < n; i ++ ) scanf("%lld", &a[i]);
	for (int i = 0; i < n; i ++ ) scanf("%lld", &b[i]);
	sort(a, a + n);
	sort(b, b + n);
	reverse(a, a + n);
	
	LL l = 0LL, r = 1e12 + 10;
	while (l < r)
	{
		LL mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1LL;
	}
	printf("%lld\n", r);
    return 0;
}