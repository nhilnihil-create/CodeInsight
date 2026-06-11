#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

#define endl "\n"

ll pf(ll n)
{
	vector<pair<ll, ll>> primes;
	ll cnt = 0;
	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i != 0)
			continue;
		ll p = i;
		int num = 0;

		while (n % p == 0)
		{
			n /= p;
			num++;
		}

		ll id = 1;

		while(num >= id){
			num -= id;
			id++,cnt++;
		}
	}

	if (n > 1)
	{
		cnt++;
	}
	return cnt;
}

int main()
{
	faster;

	ll n;
	cin >> n;
	ll num = 2, operation = 0;

	cout << pf(n) << endl;
	return 0;
}