#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

signed main(void)
{
	int n;
	cin >> n;
	ll a[n];
	ll sum, ans;
	map<ll, ll> mp;
	rep(i, n) 
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	sum = 0;
	for (auto p : mp)
	{
		auto k = p.first;
		auto v = p.second;
		sum += v * (v - 1) / 2;
	}
	rep(i, n)
	{
		ans = sum;
		ans -= mp[a[i]] * (mp[a[i]] - 1) / 2;
		ans += (mp[a[i]] - 1) * (mp[a[i]] - 2) / 2;
		cout << ans << endl;
	}
	return 0;
}
