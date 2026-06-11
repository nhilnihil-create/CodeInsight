#include <bits/stdc++.h>
using namespace std;

int n, a[100008], loc[100008], l[2][100008], r[2][100008];
set<int> s;
set<int, greater<int>> ss;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		loc[a[i]] = i;
		s.insert(i);
		ss.insert(i);
	}
	s.insert(0);
	s.insert(n + 1);
	ss.insert(0);
	ss.insert(n + 1);
	for (int v = 1; v <= n; ++v)
	{
		int i = loc[v];
		s.erase(loc[v]);
		auto it = s.lower_bound(loc[v]);
		r[0][i] = *it;
		++it;
		if (r[0][i] <= n)
			r[1][i] = *it;
		else
			r[1][i] = n + 1;

		ss.erase(loc[v]);
		it = ss.lower_bound(loc[v]);
		l[0][i] = *it;
		++it;
		if (l[0][i] > 0)
			l[1][i] = *it;
		else
			l[1][i] = 0;
	}
	/*for (int i = 1; i <= n; ++i)
		printf("%d ", l[0][i]);
	printf("\n");
	for (int i = 1; i <= n; ++i)
		printf("%d ", l[1][i]);
	printf("\n");
	for (int i = 1; i <= n; ++i)
		printf("%d ", r[0][i]);
	printf("\n");
	for (int i = 1; i <= n; ++i)
		printf("%d ", r[1][i]);
	printf("\n");*/
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += ( 1LL*(l[0][i] - l[1][i]) * (r[0][i] - i) + 1LL*(r[1][i] - r[0][i]) * (i - l[0][i]) )* a[i];
	printf("%lld\n", ans);
}