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
int main()
{
	ll N, M;
	string S;
	cin >> N >> M >> S;

	vector<ll> ans;
	reverse(ALL(S));
	for (int i = 0; i < N;) {
		ll zeroPos = 0;
		ll stepLim = min(N - i, M);
		REPN(j, 1, stepLim + 1) {
			if (S[i + j] == '0') {
				zeroPos = j;
			}
		}
		if (zeroPos == 0) {
			cout << -1 << endl;
			return 0;
		}
		ans.emplace_back(zeroPos);
		i += zeroPos;
	}

	reverse(ALL(ans));
	for (auto one : ans) {
		cout << one << " ";
	}
	cout << endl;
	return 0;
}
