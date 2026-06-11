#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 5;
const int INF = 1e9 + 7;

int x, n;
vector<int> a(N);

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> n;
	a.resize(n);
	map<int, int> mp;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		++mp[a[i]];
	}
	for (int i = 0; i <= n; i++)
	{
		if (!mp[x - i])
		{
			cout << x - i;
			return 0;
		}
		if (!mp[x + i])
		{
			cout << x + i;
			return 0;
		}
	}
	return 0;
}
//10-09-2020 17:58:39