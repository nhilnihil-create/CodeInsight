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
	vector<ll>ans;

	ll cnt = 0;

	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			ll cur = 0;
			ll add = 0;
			while (n % i == 0)
			{
				n = n / i;
				cur++;
				if ((add + 1) * (add + 2) / 2 <= cur)
					add++;
			}
			cnt += add;
		}
	}

	if (n != 1)
		cnt++;

	cout << cnt;

	return 0;
}