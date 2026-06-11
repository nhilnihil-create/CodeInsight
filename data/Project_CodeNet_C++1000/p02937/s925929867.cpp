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
// メイン
int main()
{
	string s, t;
	cin >> s >> t;

	set<ll> word[26];
	REP(i, s.size()) {
		int idx = s[i] - 'a';
		word[idx].insert(i);
	}

	ll ans = 0;
	ll tLen = t.size();
	for (ll tCnt = 0;;) {
		ll nowIdx = -1;
		for (; tCnt < tLen; tCnt++) {
			auto &wordOne = word[t[tCnt] - 'a'];
			auto idx = wordOne.lower_bound(nowIdx);
			if (idx == wordOne.end()) {
				break;
			}
			nowIdx = *idx + 1;
		}

		if (nowIdx == -1) {
			ans = -1;
			break;
		}

		if (tCnt == tLen) {
			ans += nowIdx;
			break;
		}

		ans += s.size();
	} 

	cout << ans << endl;
	return 0;
}
