#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

const ll MOD = 1e9+7;
// const ll MOD = 998244353;
const ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(ll)(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

ll N, K;

int main(int argc, char **argv)
{
	cin >> N >> K;
	ll ma = (N-2) * (N-1) / 2;
	if (ma < K)
	{
		std::cout << -1 << std::endl;
		return 0;
	}

	vector<pair<ll, ll>> add;

	std::cout << N-1 + ma - K << std::endl;
	for (ll v = 0; v < N-1; ++v)
	{
		for (ll vv = v + 1; vv < N; ++vv)
		{
			if (vv == N-1)
				std::cout << v+1 << " " << vv+1 << std::endl;
			else
				add.push_back(P(v, vv));
		}
	}

	REP(i, ma-K)
		std::cout << add[i].first+1 << " " << add[i].second+1 << std::endl;
	
}
