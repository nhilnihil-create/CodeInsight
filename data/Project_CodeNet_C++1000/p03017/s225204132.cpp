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
/* 最大公約数 */
ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

/* 最小公倍数 */
ll lcm(ll a, ll b)
{
	ll gcdRes = gcd(a, b);
	return (a * (b / gcdRes));
}

int main()
{
	ll N, A, B, C, D;
	string S;
	cin >> N >> A >> B >> C >> D >> S;

	string ans = "No";
	A--; B--, C--, D--;

	ll endPos = max(C, D);
	for (ll i = A; i < endPos; i++) {
		if (S[i] == '#' && S[i + 1] == '#') {
			goto EXIT;
		}
	}
	
	if (C < D) {
		ans = "Yes";
		goto EXIT;
	}

	endPos = min((ll)N - 2, D);
	for (ll i = B; i <= endPos; i++) {
		if (S[i - 1] == '.' && S[i] == '.' && S[i + 1] == '.') {
			ans = "Yes";
			goto EXIT;
		}
	}
	
EXIT:
	cout << ans << endl;
	return 0;
}
