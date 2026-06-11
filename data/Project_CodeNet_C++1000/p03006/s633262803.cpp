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

typedef long long           ll;
typedef pair<ll, ll>	    P;

#define ALL(x)              (x).begin(),(x).end()
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

/*-----------------------------------------------------------------------------
　処理
 -----------------------------------------------------------------------------*/
int main()
{
	ll N;
	cin >> N;
	vector<P> pos(N);
	for_each(ALL(pos), [](P &a)->void{cin >> a.first >> a.second;});

	map<P, ll> mp;
	REP(i, N){
		P top = pos[i];
		REP(j, N){
			P end = pos[j];
			ll eX = end.first - top.first;
			ll eY = end.second - top.second;
			mp[P{eX, eY}]++;
		}
	}

	ll ans = INF;
	for (auto one : mp) {
		auto pq = one.first;
		ll ansOne = 0;
		vector<bool> isUsed(N, false);
		REP(i, N) {
			P stPos = pos[i];
			if (isUsed[i])  continue;
			isUsed[i] = true;
			ansOne++;
			if (pq == P{0, 0})  continue;

			queue<P> que;
			que.push(P{ stPos.first + pq.first, stPos.second + pq.second });
			que.push(P{ stPos.first - pq.first, stPos.second - pq.second });
			while (!que.empty()) {
				P nextPos = que.front(); que.pop();
				REP(j, N){
					if (!isUsed[j]) {
						if (pos[j] == nextPos) {
							isUsed[j] = true;
							que.push(P{ pos[j].first + pq.first, pos[j].second + pq.second });
							que.push(P{ pos[j].first - pq.first, pos[j].second - pq.second });
						}
					}
				}
			}
		}
		ans = min(ans, ansOne);
	}

	cout << ans << endl;
	return 0;
}
