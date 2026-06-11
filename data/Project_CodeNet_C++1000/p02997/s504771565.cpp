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
	ll N, K;
	cin >> N >> K;

	ll totalNum = (N - 1) * (N - 2) / 2;
	
	if (totalNum < K) {
		cout << -1 << endl;
		return 0;
	}
	
	vector<P> G;
	REPN(i, 1, N) {
		G.emplace_back(0, i);
	}

	REPN(i, 1, N) {
		REPN(j, i + 1, N) {
			if (totalNum != K) {
				G.emplace_back(i, j);
				totalNum--;
			}
			if (totalNum == K) {
				goto EXIT;
			}
		}
	}

EXIT:
	cout << G.size() << endl;
	for (auto one : G) {
		cout << one.first + 1 << " " << one.second + 1<< endl;
	}

	return 0;
}
