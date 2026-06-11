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

ll N, M, S, T;
vector<vector<ll>> G;
vector<vector<ll>> dist;

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	G.resize(N);
	dist.assign(3, vector<ll>(N, -1));
	// node, cnt;

	REP(i, M)
	{
		ll a, b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
	}

	cin >> S >> T;
	--S, --T;

	queue<P> que;
	que.push(P(0, S));
	dist[0][S] = 0;
	
	while (que.size())
	{
		auto now = que.front();
		que.pop();

		ll prec = now.first;
		ll c = (prec + 1) % 3;
		ll n = now.second;

		for (auto &nv : G[n])
		{
			if (dist[c][nv] != -1) continue;
			dist[c][nv] = dist[prec][n] + 1;
			que.push(P(c, nv));
		}
	}

	ll t = dist[0][T];
	std::cout << (t == -1 ? t : t/3)<< std::endl;
	return 0;
}
