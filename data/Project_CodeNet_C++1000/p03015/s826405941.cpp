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
int main()
{
	string L;
	cin >> L;

	ll lLen = L.size();
	vector<vector<ll>> dp(lLen + 1, vector<ll>(2, 0));
	dp[0][0] = 1;
	REP(i, lLen) {
		if (L[i] == '1') {
			dp[i + 1][0] += dp[i][0] * 2;
			dp[i + 1][1] += dp[i][0];
		} else {
			dp[i + 1][0] += dp[i][0];
		}
		dp[i + 1][1] += dp[i][1] * 3;
		dp[i + 1][0] %= MOD;
		dp[i + 1][1] %= MOD;
	}

	ll ans = 0;
	ans += dp[lLen][0];
	ans += dp[lLen][1];
	ans %= MOD;
	cout << ans << endl;
	return 0;
}
