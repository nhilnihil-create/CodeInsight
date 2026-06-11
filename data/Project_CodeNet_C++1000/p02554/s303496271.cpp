#pragma GCC optimize("Ofast", "unroll-loops")

// #define USE_AC_LIBRARY

#include <bits/stdc++.h>
#ifdef USE_AC_LIBRARY
#include <atcoder/all>
#endif

using namespace std;
#ifdef USE_AC_LIBRARY
using namespace atcoder;
#endif

#define ll long long
#define ld long double

ll modpow(ll a, ll b, ll mod = 1000000007LL){
	if (b == 0) return 1LL;
	ll tmp = modpow(a, b / 2, mod);
	if (b % 2)
		return tmp * tmp % mod * a % mod;
	return tmp * tmp % mod;
}

constexpr ll mod = 1000000007LL;

int main(void){
	int N; cin >> N;
	ll res = ((modpow(10, N) - 2 * modpow(9, N) % mod + mod)	% mod + modpow(8, N)) % mod;
	cout << res << endl;
	return 0; 
}