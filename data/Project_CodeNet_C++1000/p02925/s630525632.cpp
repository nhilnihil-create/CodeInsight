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
vector<vector<int>>	G;
vector<bool>		isVisited;
vector<int>			depth;
int dfs(int from, int to)
{
	if (isVisited[to]) {
		return depth[to];
	}

	int depthRes = 1;
	isVisited[to] = true;
	for (auto nextTo : G[to]) {
		if (from != nextTo) {
			int depthOne = dfs(to, nextTo);
			if (depthOne == -1) {
				// 閉路あり
				return -1;
			}
			depthRes = max(depthOne + 1, depthRes);
		}
	}

	depth[to] = depthRes;
	return depthRes;
}

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> A(N, vector<int>(N - 1));
	REP(i, N) {
		REP(j, N - 1) {
			cin >> A[i][j];
			A[i][j]--;
		}
	}

	int id = 0;
	vector<vector<int>> path(N, vector<int>(N, -1));
	REP(from, N) {
		REP(to, N) {
			if (from != to) {
				if (path[from][to] == -1) {
					path[from][to] = id;
					path[to][from] = id;
					id++;
				}
			}
		}
	}

	int totalV = N * (N - 1) / 2;
	G.resize(totalV);
	REP(from, N) {
		REP(j, N - 2) {
			int prev = path[from][A[from][j]];
			int next = path[from][A[from][j + 1]];
			G[prev].emplace_back(next);
		}
	}

	int ans = 0;
	isVisited.resize(totalV, false);
	depth.resize(totalV, -1);
	REP(i, totalV) {
		int ansOne = dfs(-1, i);
		if (ansOne == -1) {
			ans = -1;
			break;
		} else {
			ans = max(ans, ansOne);
		}
	}

	cout << ans << endl;
	return 0;
}
