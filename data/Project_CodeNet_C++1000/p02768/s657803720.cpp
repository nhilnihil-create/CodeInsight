#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

ll modPow(ll a, ll n)
{
	if (n == 1) return a%MOD;
	if (n&1) return (a*modPow(a, n-1)) % MOD;
	ll tmp = modPow(a, n/2);
	return (tmp*tmp) % MOD;
}

ll fac(ll n, ll a)
{
	ll res{1};
	for (ll i = n; i >= a; --i)
		(res *= i) %= MOD;
	return res;
}

int main(int argc, char **argv)
{
	ll N, A, B; cin >> N >> A >> B;

	ll npow = modPow(2, N);
	ll Xa = fac(N, N-A+1);
	ll Ya = fac(A, 1);
	ll Xb = fac(N, N-B+1);
	ll Yb = fac(B, 1);

	ll subA = (Xa * modPow(Ya, MOD-2)) % MOD;
	ll subB = (Xb * modPow(Yb, MOD-2)) % MOD;

	// std::cout << "subA : " << subA << std::endl;
	// std::cout << "subB : " << subB << std::endl;

	std::cout << (MOD*2 + npow - subA - subB - 1) % MOD << std::endl;
}