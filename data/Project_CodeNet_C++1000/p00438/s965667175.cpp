#include<iostream>
#include<iomanip>
#include<algorithm>
#include<array>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<functional>
#include<limits>
#include<list>
#include<map>
#include<numeric>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define dump(o) {cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) {cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
const int MOD = 1e9 + 7;

signed main() {
	for (int a, b; cin >> a >> b&&a;) {
		int n; cin >> n;
		int dp[20][20] = {};
		rep(i, 0, n) {
			int x, y; cin >> x >> y;
			x--; y--;
			dp[x][y] = -1;
		}
		dp[0][0] = 1;
		rep(x, 0, a)rep(y, 0, b) {
			if (dp[x + 1][y] != -1 && dp[x][y] != -1)dp[x + 1][y] += dp[x][y];
			if (dp[x][y + 1] != -1 && dp[x][y] != -1)dp[x][y + 1] += dp[x][y];
		}
		cout << dp[a - 1][b - 1] << endl;
	}
	return 0;
}