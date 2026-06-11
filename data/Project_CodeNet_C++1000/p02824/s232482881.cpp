#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, v, p, a[100010];
int tmp[100010];
inline bool check(int x)
{
	int cnt = 0;
	priority_queue <int> q;
	long long ret = (v - 1) * m;
	for (register int i = 1;i <= n;i ++)
	{
		tmp[i] = a[i];
	}
	tmp[x] += m;
	for (register int i = 1;i <= n;i ++)
	{
		if(i == x) continue;
		int num = tmp[x] - tmp[i];
		if(num < 0)
		{
			cnt ++;
			ret -= m;
			if(ret < 0) ret = 0;
		}
		else
		{
			if(num < m)
			{
				q.push(m - num);
				ret -= num;
			}
			else
			{
				ret -= m;
			}
			if(ret < 0)	ret = 0;
		}
	}
	while(!q.empty())
	{
		if(ret <= 0) break;
		cnt ++;
		int tp = q.top();
		q.pop();
		ret -= tp;
	}
	return cnt < p;
}

inline int find()
{
	int l = 1, r = n;
	while(r - l >= 3)
	{
		int mid = (l + r) >> 1;
		if(check(mid))
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	for (register int i = l;i <= r;i ++)
	{
		if(check(i)) return i;
	}
	return n + 1;
}

signed main() {
	scanf("%lld%lld%lld%lld", &n, &m, &v, &p);
	for (register int i = 1;i <= n;i ++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	printf("%lld\n", n - find() + 1);
	return 0;
}
