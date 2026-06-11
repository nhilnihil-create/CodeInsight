#include<bits/stdc++.h>
using namespace std;
#define ll         long long
#define mod        1000000007
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define inf        1e18
#define ps(x,y)    fixed<<setprecision(y)<<x

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n;
	cin >> n;
	ll a[n + 1];
	ll total = 0;
	for (ll i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	std::vector<ll> sum(n + 1, 0);
	std::vector<ll> diff(n + 1, 0);
	for (ll i = 1; i <= n; ++i)
	{
		sum[i] = i + a[i];
	}
	for (ll i = 1; i <= n ; ++i)
	{
		diff[i] = i - a[i];
	}
	sort(sum.begin() + 1, sum.end());
	sort(diff.begin() + 1, diff.end());

	for (ll i = 1, j = 1; i <= n && j <= n ; )
	{
		if (sum[i] == diff[j])
		{
			total++;
			ll a1 = 0;
			ll a2 = 0;
			while ((i + 1 <= n) && (sum[i + 1] == sum[i]))
			{
				a1++;
				i++;

			}
			while ((j + 1 <= n ) && ( diff[j + 1] == diff[j]))
			{
				a2++;
				j++;
			}
			i++, j++;
			total = total + (a1 + 1) * (a2 + 1) - 1;


		}
		else if (sum[i] < diff[j])
		{
			i++;
		}
		else
			j++;
	}

	cout << total;
}