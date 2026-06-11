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
#define REP(i, n)           for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n)       for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define INF                 (ll)2e9
#define MOD                 (1000 * 1000 * 1000 + 7)
#define Ceil(x, n)          (((((x))+((n)-1))/n))
#define CeilN(x, n)         (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)        ((x)-(x)%(n))
#define IsOdd(x)            (((x)&0x01UL) == 0x01UL)
#define IsEven(x)           (!IsOdd((x)))
#define M_PI                3.14159265358979323846
typedef long long           ll;
typedef pair<ll, ll>	    P;

/*-----------------------------------------------------------------------------
　処理
 -----------------------------------------------------------------------------*/
int main()
{
	ll N;
	cin >> N;
	vector<P> P(N);
	REP(i, N) {
		cin >> P[i].first;
		P[i].second = i + 1;
	}
	sort(P.rbegin(), P.rend());

	ll ans = 0;
	multiset<ll> s;
	s.insert(0);
	s.insert(0);
	s.insert(N + 1);
	s.insert(N + 1);
	for (auto one : P) {
		auto it = s.lower_bound(one.second);
		ll posR = *it;
		it++;
		ll posRR = *it;
		it--;
		it--;
		ll posL = *it;
		it--;
		ll posLL = *it;

		ll ansOneL = one.first * (posL - posLL) * (posR - one.second);
		ll ansOneR = one.first * (posRR - posR) * (one.second - posL);
		ans += ansOneL;
		ans += ansOneR;

		s.insert(one.second);
	}

	cout << ans << endl;

	return 0;
}
