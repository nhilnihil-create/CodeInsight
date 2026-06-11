#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main(int argc, char **argv)
{
	ll N; cin >> N;
	vector<ll> A(N); REP(i, N) cin >> A[i];

	ll fac{1};
	ll res{0};
	REP(b, 60)
	{
		ll o{0}, e{0};
		REP(i, N)
		{
			if (A[i] & (1ll<<b)) ++o;
			else ++e;
		}

		(res += fac * o % MOD * e) %= MOD;
		(fac *= 2) %= MOD;
	}
	std::cout << res << std::endl;
}
