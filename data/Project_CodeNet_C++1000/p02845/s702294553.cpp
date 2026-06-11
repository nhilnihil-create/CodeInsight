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
	vector<ll> A(N);
	REP(i, N) cin >> A[i];

	vector<ll> V(100000, 0);

	ll res{1};
	REP(i, N)
	{
		ll &t = A[i];

		if (t == 0)
		{
			(res *= (3-V[t])) %= MOD;
			++V[t];
		}
		else
		{
			(res *= (V[t-1] - V[t])) %= MOD;
			++V[t];
		}
	}
	std::cout << res << std::endl;
}
