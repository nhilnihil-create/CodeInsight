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

ll N, M;
ll s, t;
vector<vector<ll>> G;

int main(int argc, char **argv)
{
	cin >> N >> M;
	G.resize(N);
	REP(i, M)
	{
		ll a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
	}
	cin >> s >> t;
	--s, --t;

	vector<vector<ll>> dist(N, vector<ll>(3, -1));
	queue<P> que;
	dist[s][0] = 0;
	que.push({s, 0});
	while (que.size())
	{
		P p = que.front(); que.pop();
		ll now = p.first;
		ll tmp = p.second;
		ll ntmp = (tmp + 1) % 3;

		for (auto &nv : G[now])
		{
			if (dist[nv][ntmp] != -1) continue;

			dist[nv][ntmp] = dist[now][tmp] + 1;
			que.push({nv, ntmp});
		}
	}

	ll res;
	if (dist[t][0] == -1) res = -1;
	else res = dist[t][0] / 3;
	std::cout << res << std::endl;
}
