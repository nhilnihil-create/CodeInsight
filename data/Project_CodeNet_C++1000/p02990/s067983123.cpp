#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>
#include <cmath>
#include <tuple>
#include <vector>
#include <bitset>
#include <stack>
#include <iomanip>
#include <set>
#include <queue>
#include <map>


typedef long long ll;
typedef unsigned long long ull;
#define mk make_pair
#define mkt make_tuple
#define fi first
#define se second


using namespace std;
ll const MOD = 1e9 + 7;

ll binPow(ll a, ll n) {
	if (n == 1) return a;
	if (n % 2) return (a * (binPow(a, n - 1ll)%MOD)) % MOD;
	ll c = binPow(a, n / 2ll)%MOD;
	return (c * c) % MOD;
}

ll ans(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	ll num = 1ll;
	for (ll j = 1ll; j <= n; j++) {
		num *= j;
		num %= MOD;
	}

	ll den = 1ll;
	for (ll j = 1ll; j <= n - k; j++) {
		den *= j;
		den %= MOD;
	}
	for (ll j = 1ll; j <= k; j++) {
		den *= j;
		den %= MOD;
	}
	return (num * (binPow(den, MOD - 2ll) % MOD)) % MOD;
}

int main()
{
	ll n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		ll curans = ans(n - k + 1ll, i);
		curans %= MOD;
		curans *= ans(k - 1ll, i - 1ll);
		curans %= MOD;
		cout << curans << endl;
	}
	
}
