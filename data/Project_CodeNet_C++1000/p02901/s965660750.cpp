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
#include<unordered_map>
#include<unordered_set>
#include<bitset>
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
typedef pair<Int, Int> PI;
typedef pair<int, int> P;
typedef vector<double> vec;
typedef vector<vec> mat;
const int N = 100005;
//////////////////////////////

int dp[1003][5003];

void solve()
{
	int n, m; cin >> n >> m;
	vector<int> a(m), b(m), c(m, 0);
	REP(i, m) {
		cin >> a[i] >> b[i];
		REP(j, b[i]) {
			int t; cin >> t; t--;
			c[i] += (1 << t);
		}
	}
	REP(i, 1003) REP(j, 5003) dp[i][j] = INF;
	dp[0][0] = 0;

	REP(i, m) REP(s, (1 << n)) {
		dp[i + 1][s] = min(dp[i + 1][s], dp[i][s]);
		dp[i + 1][s | c[i]] = min(dp[i + 1][s | c[i]], dp[i][s] + a[i]);
	}

	cout << (dp[m][(1 << n) - 1] < INF ? dp[m][(1 << n) - 1] : -1) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
