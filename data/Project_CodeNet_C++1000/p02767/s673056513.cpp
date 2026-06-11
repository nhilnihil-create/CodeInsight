#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, s = 0;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s += a[i];
	}
	ll poz = s / n;
	ll poz1 = s / n + 1;
	ll st = 0;
	ll st1 = 0;
	for (auto x : a)
	{
		st += ((x - poz) * (x - poz));
		st1 += ((x - poz1) * (x - poz1));
	}
	cout << min(st, st1);
	return 0;
}
