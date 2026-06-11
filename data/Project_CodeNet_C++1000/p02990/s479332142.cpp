#include <iostream>
#include <iomanip>
#include <complex>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>

#define mod 1000000007
#define point complex <double>
#define p pair<double,double>
#define ll long long
#define pi acos(-1)

using namespace std;

ll fact[2005], inv[2005], dp[2005][2005][2];

ll fp(int base, int power)
{
	if (power == 0) return 1;
	ll ans = fp(base, power / 2);
	ans = (ans * ans) % mod;
	if (power % 2 != 0) ans = (ans * (base % mod)) % mod;
	return ans;
}

void calc()
{
	fact[0] = inv[0] = 1;
	for (ll i = 1; i <= 2000; i++)
	{
		fact[i] = (i * fact[i - 1]) % mod;
		inv[i] = fp(fact[i], mod - 2);
	}
}

ll ncr(int n, int r)
{
	return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}

ll stars_and_bars(int stars, int bars)
{
	return ncr(stars - 1, bars - 1);
}

// states: consecutive_blue cnt , all left red cnt , flag if prev is blue or not 

ll solve(int blue, int red, bool prev)
{
	if (!red && !blue) return 1;
	if (dp[blue][red][prev] != -1)return dp[blue][red][prev];
	ll ans = 0;
	if (blue && !prev) ans = (ans + solve(blue - 1, red, true)) % mod;
	if (red) ans = (ans + solve(blue, red - 1, false)) % mod;
	return dp[blue][red][prev] = ans;
}

int main()
{
	calc();
	memset(dp, -1, sizeof dp);
	int n, k, r;
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		cout << (stars_and_bars(k, i) * solve(i, n - k, 0)) % mod << '\n';
	return 0;
}
