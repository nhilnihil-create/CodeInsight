#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define reverse(x) reverse(x.begin(), x.end())
#define sort(x) sort(x.begin(), x.end())
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long,long long>
#define f first
#define s second
typedef long long ll;
const ll mod = 1e9+7;
using namespace std;

ll modpow(ll a, ll b, ll m) {
	ll p = 1, q = a;
	for (int i=0;i<32;i++) {
		if((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
		q *= q; q %= m;
	}
	return p;
}

ll Div(ll a, ll b, ll m) {
	return (a * modpow(b, m - 2, m)) % m;
}

ll ncr(ll n, ll r) {
	if (n < r || r < 0) return 0;
	ll rem = 1;
	for (ll i = n - r + 1; i <= n; i++) { rem *= i; rem %= mod; }
	for (int i = 1; i <= r; i++) rem = Div(rem, i, mod);
	return rem;
}

int main(){
	ll N, A, B;
	cin >> N >> A >> B;

	ll V1 = modpow(2, N, mod); V1 = (V1 + mod - 1LL) % mod;
	ll V2 = ncr(N, A);
	ll V3 = ncr(N, B);
	cout << (V1 - V2 - V3 + mod * mod) % mod << endl;
	return 0;

}
