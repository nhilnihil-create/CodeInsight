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

int n, h, mx;
int a[1100], b[1100];
int dp[N];

void solve()
{
	cin >> h >> n;
	REP(i, n) {
		cin >> a[i] >> b[i];
		mx = max(mx, a[i]);
	}

	RREP(i, h + mx) {
		dp[i] = INF;
		REP(j, n) {			
			int k = i - a[j];
			if (k < 0) {
				dp[i] = min(dp[i], b[j]);
			}
			else {
				dp[i] = min(dp[i], dp[k] + b[j]);
			}
		}
	}
	int ans = INF;
	for (int i = h; i < h + mx; i++) ans = min(ans, dp[i]);
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
