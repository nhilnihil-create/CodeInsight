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
	ll N, K; cin >> N >> K;
	vector<ll> S(N);
	REP(i, N)
	{
		char c; cin >> c;
		if (c == 'L')
			S[i] = 0;
		else
			S[i] = 1;
	}

	ll t{S[0]};
	for (ll i = 0; i < N; ++i)
	{
		if (i+1 < N && S[i] != t && S[i+1] == t)
			--K;
		S[i] = t;
		if (K == 0) break;
	}

	ll res{0};
	for (ll i = 0; i < N;)
	{
		ll j = i + 1;
		while (j < N && S[i] == S[j])
		{
			++j;
		}
		res += j - i - 1;
		i = j;
	}

	std::cout << res << std::endl;
}
