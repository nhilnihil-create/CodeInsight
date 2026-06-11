#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll k, n;
	cin >> k >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	ll dmax = abs(a[n - 1] - k) + a[0];
	ll s = dmax;
	for (int i = 1; i < n; i++)
	{
		ll c = abs(a[i] - a[i - 1]);
		if (dmax < c)
			dmax = c;
		s += c;
	}
	s -= dmax;
	cout << s;
	return 0;
}
