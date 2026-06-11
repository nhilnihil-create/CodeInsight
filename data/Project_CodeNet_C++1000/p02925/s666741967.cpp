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

int dx[4]{0, 1, 0, -1};
int dy[4]{1, 0, -1, 0};

ll N;
vector<vector<ll>> G;
ll seen[1000*1000];
ll dist[1000*1000];

ll dfs(ll n)
{
	if (seen[n] == 2) return dist[n];
	seen[n] = 1;
	for (auto nv : G[n])
	{
		if (seen[nv] == 1)
		{
			std::cout << -1 << std::endl;
			exit(0);
		}

		dist[n] = max(dist[n], dfs(nv) + 1);
	}

	seen[n] = 2;
	return dist[n];
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll N; cin >> N;
	G.resize(N*N);

	auto f = [](ll i, ll j) -> ll
			 {
				 if (i < j) swap(i, j);
				 return i*(i-1)/2 + j + 1;
			 };

	REP(i, N)
	{
		ll pre{0};
		REP(j, N-1)
		{
			ll a; cin >> a;
			--a;
			ll now = f(i, a);
			G[pre].push_back(now);
			pre = now;
		}
	}

	std::cout << dfs(0) << std::endl;
	
	return 0;
}
