#include <bits/stdc++.h>
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define deb(x) cout<<#x<<"="<<x<<endl;
#define endl '\n'
#define M 1000000007
#define int long long
#define INF 1e18
#define max_n 1000000

using namespace std;

void solve()
{
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	ll l = 1, r = 1e9;
	while (l < r)
	{
		ll m = l + (r - l) / 2;
		ll req = 0;
		for (int i = 0; i < n; ++i)
		{
			if (a[i] % m == 0)
			{
				req += a[i] / m - 1;
			}
			else req += a[i] / m;
		}
		if (req <= k)
		{
			r = m;
		}
		else l = m + 1;
	}
	cout << r << endl;
}

int32_t main()
{
	IOS
	ll T = 1;
	// cin >> T;
	for (ll i = 1; i <= T; ++i)
	{
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}