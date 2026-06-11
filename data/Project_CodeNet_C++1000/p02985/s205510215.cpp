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

ll K, N;
vector<vector<ll>> G;

ll dfs(ll v, ll pre = -1)
{
	ll can;
	if (pre == -1)
		can = K-1;
	else
		can = K-2;

	if (K < G[v].size()) return 0;
	else
	{
		ll res{1};
		for (auto &nv : G[v])
		{
			if (nv == pre) continue;
			(res *= can--) %= MOD;
			(res *= dfs(nv, v)) %= MOD;
		}
		return res;
	}
}

int main(int argc, char **argv)
{
	cin >> N >> K;
	G.resize(N);

	REP(i, N-1)
	{
		ll a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	ll res = K*dfs(0, -1) % MOD;
	std::cout << res << std::endl;
}
