#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 5;
const int INF = 1e9 + 7;

int n, k, d, a;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	map<int, int> mp;
	while (k--)
	{
		cin >> d;
		while (d--)
		{
			cin >> a;
			mp[a] = 1;
		}
	}
	cout << n - mp.size();
	return 0;
}
//11-09-2020 17:37:32