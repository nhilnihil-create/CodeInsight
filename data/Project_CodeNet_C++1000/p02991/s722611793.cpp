#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
#include <numeric>
#include <functional>

using namespace std;
#define ALL(x)              (x).begin(),(x).end()
typedef long long           ll;
#define REP(i, n)           for (ll i = 0 ; i < (ll)n ; ++i)
#define REPN(i, m, n)       for (ll i = m ; i < (ll)n ; ++i)
#define INF                 (ll)1e9
#define MOD                 (1000 * 1000 * 1000 + 7)
#define Ceil(x, n)          (((((x))+((n)-1))/n))
#define CeilN(x, n)         (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)        ((x)-(x)%(n))
#define IsOdd(x)            (((x)&0x01UL) == 0x01UL)
#define IsEven(x)           (!IsOdd((x)))
#define M_PI                3.14159265358979323846
typedef pair<ll, ll>	    P;

/*-----------------------------------------------------------------------------
　処理
 -----------------------------------------------------------------------------*/
// 枝定義
struct Edge
{
	ll to;
	ll cost;
	Edge(){}
	Edge(ll to, ll cost) : to(to), cost(cost){}
};

struct queParam
{
	ll v;
	ll cost;
	ll status;
	queParam(ll v, ll cost, ll status) : v(v), cost(cost), status(status){}
	bool operator<(const queParam &a) const {
		return cost > a.cost;
	}
};

// グラフ定義(二次元配列)
template <class E>
using Graph = vector<vector<E>>;

// 拡張ダイクストラ
class ExDijkstra
{
private:
	const ll statusNum = 3;

public:
	// res[i] = sからiまでの最短距離
	const ll InfVal = 1e18;
	vector<vector<ll>> res;

public:
	ExDijkstra(const Graph<Edge> &G, int startPos, ll initStatus)
	{
		int V = (int)G.size();
		res = vector<vector<ll>>(V, vector<ll>(statusNum, InfVal));

		priority_queue<queParam> que;
		que.emplace(startPos, 0, initStatus);
		res[startPos][initStatus] = 0;
		
		while (!que.empty()) {
			queParam qOne = que.top(); que.pop();

			// 違う最短距離がキューにあるのでスキップ
			if (res[qOne.v][qOne.status] < qOne.cost) {
				continue;
			}

			// 最短距離を更新
			for (Edge e : G[qOne.v]) {
				ll nextStatus = (qOne.status + 1) % 3;
				ll &nowCost = res[e.to][nextStatus];
				ll newCost = res[qOne.v][qOne.status] + e.cost;
				if (nowCost > newCost) {
					nowCost = newCost;
					que.emplace(e.to, newCost, nextStatus);
				}
			}
		}
	}
};

int main()
{
	int N, M;
	cin >> N >> M;
	Graph<Edge>	G(N);
	REP(i, M) {
		ll u, v;
		cin >> u >> v;
		u--, v--;
		G[u].emplace_back(Edge(v, 1));
	}

	int S, T;
	cin >> S >> T;
	S--; T--;

	ExDijkstra dijk(G, S, 0);

	ll ans = -1;
	if (dijk.res[T][0] != dijk.InfVal) {
		ans = dijk.res[T][0] / 3;
	}
	cout << ans << endl;
	return 0;
}
