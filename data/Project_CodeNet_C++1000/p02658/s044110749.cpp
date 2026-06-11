#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e18;

int n;
vector<int> a(N);

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ans = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == 0)
		{
			cout << 0;
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (ans <= (INF / a[i]))
			ans *= a[i];
		else
		{
			cout << -1;
			return 0;
		}
	}
	cout << ans;
	return 0;
}
//10-09-2020 18:18:29