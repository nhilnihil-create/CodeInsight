#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

int main(int argc, char **argv)
{
	ll N; cin >> N;
	vector<ll> A(N); REP(i, N) cin >> A[i];

	ll a{0};

	REP(i, N)
	{
		if (i&1)
		{
			a -= A[i];
		}
		else
			a += A[i];
	}

	std::cout << a << " ";
	for (ll i = 0; i < N-1; ++i)
	{
		a = 2*A[i] - a;
		std::cout << a << " ";
	}

	std::cout << std::endl;
}