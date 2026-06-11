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
#define REP(i, n)           for (int (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n)       for (int (i) = m ; (i) < (ll)(n) ; ++(i))
#define INF                 (int)2e9
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
	int N;
	cin >> N;

	vector<vector<int>> A(N, vector<int>(N));
	REP(i, N) {
		REP(j, N - 1) {
			cin >> A[i][j];
			A[i][j]--;
		}
	}

	queue<int> nowReq;
	REP(j, N) {
		nowReq.push(j);
	}
	vector<int> idxAll(N, 0);
	int ans = 0;
	while (!nowReq.empty()) {
		bool isExec = false;
		vector<int> isExecAll(N, false);
		queue<int> nextReq;
		while (!nowReq.empty()) {
			int idx1 = nowReq.front();
			nowReq.pop();
			if (idxAll[idx1] < N - 1) {
				int idx2 = A[idx1][idxAll[idx1]];
				int idx3 = A[idx2][idxAll[idx2]];
				if (idx1 == idx3) {
					if (!isExecAll[idx1] && !isExecAll[idx2]) {
						idxAll[idx1]++;
						idxAll[idx2]++;
						isExec = true;
						isExecAll[idx1] = true;
						isExecAll[idx2] = true;
						nextReq.push(idx1);
						nextReq.push(idx2);
					}
				}
			}
		}

		if (isExec) {
			ans++;
		}
		nowReq = nextReq;
	}

	REP(j, N) {
		if (idxAll[j] != N - 1) {
			ans = -1;
			break;
		}
	}

	cout << ans << endl;
	return 0;
}
