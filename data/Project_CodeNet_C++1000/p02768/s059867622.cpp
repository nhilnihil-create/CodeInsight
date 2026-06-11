#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <numeric>
#include <iterator>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = 1ll << 60;
const ll mod = (ll)1e9 + 7;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define print(s) cout << s;
#define println(s) cout << s << endl;
#define printd(s, f) cout << fixed << setprecision(f) << s << endl;


ll power(ll m, ll n)
{
	ll x = 1;
	if (n > 0)
	{
		x = power(m, n / 2);
		if (n % 2 == 0)
		{
			x = (x * x) % mod;
		}
		else
		{
			x = (((x * x) % mod) * m) % mod;
		}
	}

	return x;
}

ll com(ll n, ll k)
{
	ull x = 1;
	ull y = 1;
	for (ll i = k; i >= 1; i--)
	{
		x = (x * (n - i + 1)) % mod;
		y = (y * i) % mod;
	}

	return x / y;
}

// nCm を求める
class Com
{
	public:
	const int MAX = 510000;

	vector<ll> fac, finv, inv;

	void init()
	{
		fac.resize(MAX);
		fac[0] = fac[1] = 1;

		finv.resize(MAX);
		finv[0] = finv[1] = 1;

		inv.resize(MAX);
		inv[1] = 1;

		for (int i = 2; i < MAX; i++)
		{
			fac[i] = fac[i - 1] * i % mod;
			inv[i] = mod - inv[mod % i] * (mod / i) % mod;
			finv[i] = finv[i - 1] * inv[i] % mod;
		}
	}

	ll get(int n, int k)
	{
		if (n < k || n < 0 || k < 0)
		{
			return 0;
		}
		return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
	}
};


int main()
{
	ll n, a, b;
	cin >> n >> a >> b;

	ull p = power(2, n);

	Com c;
	c.init();

	ll v1 = 1;
	for (ll i = n; i > n - a; i--) {
		v1 = (v1 * i) % mod;
	}
	ll v2 = 1;
	for (ll i = n; i > n - b; i--) {
		v2 = (v2 * i) % mod;
	}
	v1 = (v1 * c.finv[a]) % mod;
	v2 = (v2 * c.finv[b]) % mod;

	ll res = p - v1 - v2 - 1;
	res += 10 * mod;
	println(res % mod);
}
