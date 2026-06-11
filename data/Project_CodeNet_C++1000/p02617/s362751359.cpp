#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD (int) 1e9+7
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define vi vector<int>
ll fun(ll n) {
	return (n * (n + 1)) / 2;
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out1.txt", "w", stdout);
#endif
	fio;
	ll n;
	cin >> n;
	ll ans = 0;
	for (ll i = 1; i <= n; i++)
		ans += fun(i);
	for (ll i = 0; i < n - 1; i++) {
		ll a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		ll temp = a * (n - b + 1);
		ans -= temp;
	}
	cout << ans << endl;
	return 0;
}