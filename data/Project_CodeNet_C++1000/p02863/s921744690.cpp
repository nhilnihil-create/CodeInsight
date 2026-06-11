#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
#include <numeric>
#include <time.h>
#include <chrono>
#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,a,b) for(ll i=a;i>b;i--)
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
#define ct(a) cout<<a<<endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define repl(i,l,r) for(int i=(1);i<(r);i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
static const double pi = 3.141592653589793;
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll INF = (1LL << 31) - 1;
const ll mod = 1e9 + 7;


int N, T;
vector<pair<int, int>>AB;
int dp[3000 + 10][3000 + 10];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int ans = 0;
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		AB.push_back(make_pair(a, b));
	}
	sort(AB.begin(), AB.end());

	dp[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= T - 1; j++) {
			dp[i][j] = dp[i - 1][j];

			ans = max(ans, dp[i][j] + AB[i - 1].second);
			if (j - AB[i - 1].first >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - AB[i - 1].first] + AB[i - 1].second);
		}
	}
	cout << ans << endl;

	return 0;

}