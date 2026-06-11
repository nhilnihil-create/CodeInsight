#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>
#define all(x) (x).begin(), (x).end()
#define xx first
#define yy second

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n), b(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	priority_queue<ii> q;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
		q.emplace(b[i], i);
	}

	i64 ans = 0;
	while (!q.empty())
	{
		auto top = q.top();
		q.pop();

		if (top.xx == a[top.yy])
			continue;

		int l = b[(top.yy + n - 1) % n];
		int r = b[(top.yy + 1) % n];
		int m = max(l, r);
		int dec = l + r;

		int t = (b[top.yy] - m + 1 + dec - 1) / dec;
		if (l == a[(top.yy + n - 1) % n] && r == a[(top.yy + 1) % n])
			t = (b[top.yy] - a[top.yy] + dec - 1) / dec;

		b[top.yy] -= t * dec;

		if (b[top.yy] < a[top.yy])
		{
			printf("-1\n");
			return 0;
		}

		q.emplace(b[top.yy], top.yy);
		ans += t;
	}

	printf("%lld\n", ans);

	return 0;
}
