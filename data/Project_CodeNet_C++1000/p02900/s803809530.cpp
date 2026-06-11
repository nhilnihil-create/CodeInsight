#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using Pair = pair<int, int>;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define INF 1000000007
#define SEP " "

void	prime_factorization(ll n, map<ll, ll> &factors)
{
	factors = map<ll, ll>();
	ll lim = n;
	for (ll f = 2; f * f <= lim; f++)
	{
		while (n % f == 0)
		{
			factors[f]++;
			n /= f;
		}
	}
	if (n != 1)
		factors[n]++;
}

int     main()
{
	ll a, b;
	cin >> a >> b;
	map<ll, ll> factor;
	prime_factorization(__gcd(a, b), factor);
	cout << factor.size() + 1 << endl;
}


