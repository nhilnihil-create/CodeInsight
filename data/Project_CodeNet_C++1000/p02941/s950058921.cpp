#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 200005
#define ll long long
int a[N], b[N], n;
priority_queue<pair<int, int> > q;
ll ans;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), q.push(make_pair(a[i], i));
	while (!q.empty())
	{
		pair<int, int>t = q.top();
		q.pop();
		if (b[t.second] == t.first) continue;
		if (b[t.second] > t.first)
		{
			puts("-1");
			return 0;
		}
		int dis = t.first - b[t.second];
		int sum = a[t.second - 1] + a[t.second + 1];
		if (t.second == 1)
			sum += a[n];
		if (t.second == n)
			sum += a[1];
		if (sum > dis)
		{
			puts("-1");
			return 0;
		}
		int add = dis / sum;
		ans += add;
		a[t.second] -= add * sum;
		t.first = a[t.second];
		q.push(t);
	}
	printf("%lld\n", ans);
}
