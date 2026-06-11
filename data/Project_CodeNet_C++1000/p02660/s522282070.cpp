#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second

map<int, int> m1;

void factors(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
			{
				m1[i]++;
				n = n / i;
			}
		}
	}
	if (n > 1)
		m1[n] = 1;
}

void solve()
{
	int n;
	cin >> n;
	factors(n);

	int cnt = 0;
	for (auto i : m1)
	{
		int x = 0, y = 0;
		while (x + y + 1 <= i.ss)
		{
			x++;
			y += x;
		}
		cnt += x;
	}
	cout << cnt << "\n";

}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
