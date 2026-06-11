#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<list>
#include <cstring>
#include <functional>
//#include<unordered_map>
//#include<unordered_set>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF ((Int)1<<60)
#define EPS (1e-10)
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
#define RREP(i,n) for(int i=1; i<=(int)(n); ++i)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);++i)
typedef long long Int;
typedef pair<Int, Int> P; 
typedef vector<double> vec;
typedef vector<vec> mat;
const int N = 200005;
//////////////////////////////


void solve()
{
	Int N, K, ans = LINF;
	cin >> N >> K;
	Int H[330];
	H[0] = 0;
	RREP(i, N) cin >> H[i];

	Int DP[330][330];
	REP(i, N + 1) {
		REP(j, N + 1) {
			DP[i][j] = LINF;
		}
	}

	DP[0][0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			for (int k = j - 1; k<i; ++k) {
				DP[i][j] = min(DP[i][j], DP[k][j - 1] + max((Int)0, H[i] - H[k]));
			}
		}
	}

	for (int i = N - K; i <= N; ++i) ans = min(ans, DP[i][N - K]);
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
