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
/* 繰り返し二乗法 (xのy乗) */
ll binpow(ll x, ll y)
{
	ll res = 1LL;
	x %= MOD;
	while (y) {
		if (y & 1) res = (res * x) % MOD;
		y >>= 1;
		x = (x * x) % MOD;
	}
	return res;
}

int main()
{
	string L;
	cin >> L;

	ll oneCnt = 0;
	ll ans = 0;
	REP(i, L.size()) {
		if (L[i] == '1') {
			ll nokori = L.size() - i - 1;
			ans += binpow(2, oneCnt) * binpow(3, nokori);
			ans %= MOD;
			oneCnt++;
		}
	}

	ans += binpow(2, oneCnt);
	ans %= MOD;
	cout << ans << endl;
	return 0;
}
