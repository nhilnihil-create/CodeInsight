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
#define DEBUG(x) std::cerr << #x << " : " << (x) << std::endl;
//#define DEBUG(x) ;

ll N, K;

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	if (K > (N-1)*(N-2)/2)
	{
		std::cout << -1 << std::endl;
		return 0;
	}

	vector<pair<ll, ll>> res;
	for (ll i = 2; i <= N; ++i)
		res.push_back(pair<ll, ll>(1, i));

	for (ll i = 2; i < N; ++i)
	{
		for (ll j = i+1; j <= N; ++j)
		{
			res.push_back(pair<ll, ll>(i, j));
		}
	}

	ll t = (N-1)*(N-2)/2 - K + N-1;
	std::cout << t << std::endl;
	for (ll i = 0; i < t; ++i)
	{
		auto nv = res[i];
		std::cout << nv.first << " " << nv.second << std::endl;
	}
	
	return 0;
}