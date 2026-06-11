#include<bits/stdc++.h>
using namespace std;
#define sz 10010
#define MOD 1000000007
#define ll long long

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	ll n; cin >> n;
	vector<ll>a(n);
	vector<ll>b(n);
	if (n % 2)
	{
		for (ll i = 0; i < n; i++)
		{
			cin >> a[i] >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		ll k = n / 2;
		cout << (b[k] - a[k] + 1);
	}
	else
	{
		for (ll i = 0; i < n; i++)
		{
			cin >> a[i] >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		ll k = n / 2 - 1;
		ll cnt = 0;
		if ((a[k] + a[k + 1]) % 2)
			cnt--;
		if ((b[k] + b[k + 1]) % 2)
			cnt++;
		ll start = (a[k + 1] + a[k]) / 2;
		ll end = (b[k + 1] + b[k]) / 2;
		// cout << start << " " << end << "\n";
		cnt += (end - start + 1);
		// 0.5
		cnt += (end - start);
		cout << cnt;
	}
	return 0;
}