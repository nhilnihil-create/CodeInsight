
#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

const ll inf = 10e17;
const ll mod = 1000000007;
const ld eps = 10e-9;


ll solve(void);

ll mulmod(ll x, ll y, ll m = mod)
{
	return (x * y) % m;
}

ll power(ll n, ll r, ll m = mod)
{
	if (r == 0) { return 1; }
	if (r == 1) { return n; }
	if (n == 0) { return 0; }
	if (n == 1) { return 1; }

	if (r % 2 == 0)
	{
		ll y = power(n, r / 2, m);
		return mulmod(y, y, m);
	}
	else
	{
		ll y = power(n, (r - 1) / 2, m);
		return n * mulmod(y, y, m) % m;
	}
}

ll solve(void)
{
	string r, s;
	cin >> r;

	for (ll i = r.length() - 1; i >= 0; i--)
		s += r[i];

	// dp[右端からi番目の文字までを選ぶ][mod13] := 場合の数
	vector<vll> dp(s.length(), vll(13,0));

	if (s[0] == '?') {
		for(ll i = 0; i < 10; i++) { dp[0][i]++; }
	}
	else { dp[0][s[0]-'0'] = 1; }


	for (ll i = 1; i < s.length(); i++)
	{
		if (s[i] == '?')
		{
			ll  p = power(10, i, 13);
			// "?" に 0 ～ 9 を入れる
			for (ll j = 0; j < 10; j++)
			{
				for (ll k = 0; k < 13; k++)
				{
					ll next = j * p + k;
					next = next % 13;
					dp[i][next] = (dp[i][next] + dp[i-1][k]) % mod;
				}
			}
		}
		else
		{
			ll j = s[i] - '0';
			for (ll k = 0; k < 13; k++)
			{
				ll next = j * power(10, i, 13) + k;
				next = next % 13;
				dp[i][next] = (dp[i][next] + dp[i - 1][k]) % mod;
			}
		}
	}

	cout << dp[s.length()-1][5] << endl;

	return 0;
}

int main(void)
{
	while (solve())
	{
	}
	return 0;
}
