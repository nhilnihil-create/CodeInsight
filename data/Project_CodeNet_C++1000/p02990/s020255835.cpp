
#include <bits/stdc++.h>
#define ReadFile freopen("input.txt","r",stdin)
#define WriteFile freopen("output.txt","w",stdout)
#define MEGA_MIND ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define M_PI 3.14159265358979323846
#define mod 1000000007
#define endl "\n"
#define point complex<ld>
using namespace std;
using ll = long long;
using lli = long long int;
using ld = long double;


const int N = 3e5 + 5, inf = 2e9;


ll fact[1000006], inv[1000006];

ll fp(ll base, ll exp)
{
	if (exp == 0)
		return 1;
	ll ans = fp(base, exp / 2);
	ans = (ans * ans) % mod;
	if (exp % 2 != 0)
		ans = (ans * (base % mod)) % mod;
	return ans;
}

void calcFacAndInv(ll n)
{
	fact[0] = inv[0] = 1;
	for (ll i = 1; i <= n; i++)
	{
		fact[i] = (i * fact[i - 1]) % mod;
		inv[i] = fp(fact[i], mod - 2);
	}
}

ll ncr(ll n, ll r)
{
	return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}

ll npr(ll n, ll r)
{
	return (fact[n] * inv[n - r]) % mod;
}

int main()
{
	MEGA_MIND
		calcFacAndInv(1000000);
	ll n, k; cin >> n >> k;
	ll r = n - k, b = k;
	for (int i = 1; i <= k; i++)
	{
		if (r+1<i)
		{
			cout << 0 << endl;
		}
		else
		cout << ncr(r + 1, i) * ncr(b - 1, i - 1) % mod << endl;
	}return 0;
}