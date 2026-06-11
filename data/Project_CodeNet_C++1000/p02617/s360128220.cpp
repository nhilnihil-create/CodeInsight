#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
pair<long long, long long> a[N];
long long n, seg[4 * N], lazy[4 * N];
vector<long long> adj[N];
void prop(long long idx, long long start, long long end)
{
	if (start > end)
		return;
	seg[idx] += lazy[idx] * (end - start + 1);
	if (start != end)
	{
		lazy[2 * idx + 1] += lazy[idx];
		lazy[2 * idx + 2] += lazy[idx];
	}
	lazy[idx] = 0;
}
void upd(long long idx, long long start, long long end, long long l, long long r, long long val)
{
	prop(idx, start, end);
	if (start > end || start > r || end < l)
		return;
	else if (start >= l && end <= r)
	{
		seg[idx] += (end - start + 1) * val;
		if (start != end)
		{
			lazy[2 * idx + 1] += val;
			lazy[2 * idx + 2] += val;
		}
	}
	else
	{
		long long mid = (start + end) / 2;
		upd(2 * idx + 1, start, mid, l, r, val);
		upd(2 * idx + 2, mid + 1, end, l, r, val);
		seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
	}
}
long long query(long long idx, long long start, long long end, long long l, long long r)
{
	prop(idx, start, end);
	if (start > end || start > r || end < l)
		return 0;
	else if (start >= l && end <= r)
		return seg[idx];
	else
	{
		long long mid = (start + end) / 2;
		long long ls = query(2 * idx + 1, start, mid, l, r);
		long long rs = query(2 * idx + 2, mid + 1, end, l, r);
		return (ls + rs);
	}
}
bool cmp(pair<long long, long long> lhs, pair<long long, long long> rhs)
{
	return lhs.second < rhs.second;
}
int  main(int argc, char const *argv[])
{
	cin >> n;
	for (long long i = 0; i < n - 1; ++i)
	{
		long long u, v;
		cin >> u >> v;
		u --;
		v --;
		if (u > v)
			swap(u, v);
		adj[u].push_back(v);
		a[i] = make_pair(u, v);
	}
	sort(a, a + n - 1, cmp);
	long long j = 0;
	for (long long i = 0; i < n; ++i)
	{
		while (j < n - 1 && a[j].second <= i)
			j ++;
		upd(0, 0, n - 1, i, i, i + 1 - j);
	}
	long long ans = query(0, 0, n - 1, 0, n - 1);
	for (long long i = 1; i < n; ++i)
	{
		upd(0, 0, n - 1, 0, n - 1, -1);
		for (long long v: adj[i - 1])
			upd(0, 0, n - 1, v, n - 1, 1);
		ans = ans + 1LL * query(0, 0, n - 1, i, n - 1);
	}
	cout << ans << '\n';
	return 0;
}