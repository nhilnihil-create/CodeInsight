#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD (int) 1e9+7
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define vi vector<int>
ll xpow(ll a, ll b)
{
	if (b == 0)
		return 1;
	if (b % 2 == 0)
	{
		ll k = xpow(a, b / 2);
		return k * k;
	}
	if (b % 2 != 0)
		return a * xpow(a, b - 1);
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);
#endif
	fio;
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.rbegin(), v.rend());
	ll sum = v[0];
	for (int i = 1; i < n / 2; i++) {
		sum += v[i] * 2;
	}
	if (n % 2 != 0)
		sum += v[n / 2];
	cout << sum << endl;
	return 0;
}