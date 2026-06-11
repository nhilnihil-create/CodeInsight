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
#define FOR(i,k,n) for(int i=(k);i<(int)(n);++i)
typedef long long Int;
typedef pair<Int, Int> P; 
typedef vector<double> vec;
typedef vector<vec> mat;
const int N = 200005;
//////////////////////////////

Int dp[2200][2200];

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	REP(i, n) cin >> a[i];

	vector<P> ai(n);
	REP(i, n) ai[i] = P(a[i], i);
	sort(ai.rbegin(), ai.rend());


	REP(i, n) {
		for (int j = 0; j <= i; ++j) {
			int l = 0, r = n - 1;
			l += j; r -= (i - j);
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1LL * ai[i].first * (r - ai[i].second));
			if (j + 1 <= n) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1LL * ai[i].first * (ai[i].second - l));
		}
	}

	Int ans = 0;
	REP(j, n + 1) ans = max(ans, dp[n][j]);
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
