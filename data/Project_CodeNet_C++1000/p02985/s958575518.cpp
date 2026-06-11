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
#define INF                 (ll)1e15
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
template <class E>
using Graph = vector<vector<E>>;

// dfs
ll K;
ll ans = 1;
Graph<int>	G;
void dfs(int from, int to, int depth, int tonariNum)
{
	ll depMax = min(2, depth);
	ll colNum = K - depMax - tonariNum;
	ans *= colNum;
	ans %= MOD;

	ll tonariCnt = 0;
	for (auto nextTo : G[to]) {
		if (nextTo != from) {
			dfs(to, nextTo, depth + 1, tonariCnt);
			tonariCnt++;
		}
	}
}

// メイン
int main()
{
	ll N;
	cin >> N >> K;
	G.resize(N);
	REP(i, N - 1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		G[a].emplace_back(b);
		G[b].emplace_back(a);
	}

	dfs(-1, 0, 0, 0);
	cout << ans << endl;
	return 0;
}