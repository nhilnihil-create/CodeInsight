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
#include <cstring>
#include <functional>
//#include<unordered_map>
//#include<unordered_set>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P; 
const int N = 100005;
//////////////////////////////

int n, k;
Int r, s, p;
string t;
Int dp[N][3];//r-0, s-1, p-2

Int points(char c)
{
	if (c == 'r') return p;
	if (c == 's') return r;
	if (c == 'p') return s;
}

int toInd(char c)
{
	if (c == 'r') return 2;
	if (c == 's') return 0;
	if (c == 'p') return 1;
}

void solve()
{
	cin >> n >> k;
	cin >> r >> s >> p;
	cin >> t;

	for (int i = 0; i < n; i++) {
		if (i - k < 0) {
			dp[i][toInd(t[i])] = points(t[i]);
		}
		else {//r-0, s-1, p-2
			if (t[i] == 'p') {//2
				dp[i][0] = max(dp[i - k][1], dp[i - k][2]);
				dp[i][1] = s + max(dp[i - k][0], dp[i - k][2]);
				dp[i][2] = max(dp[i - k][0], dp[i - k][1]);
			}
			if (t[i] == 'r') {//0
				dp[i][0] = max(dp[i - k][1], dp[i - k][2]);
				dp[i][1] = max(dp[i - k][0], dp[i - k][2]);
				dp[i][2] = p + max(dp[i - k][0], dp[i - k][1]);
			}
			if (t[i] == 's') {//1
				dp[i][0] = r + max(dp[i - k][1], dp[i - k][2]);
				dp[i][1] = max(dp[i - k][0], dp[i - k][2]);
				dp[i][2] = max(dp[i - k][0], dp[i - k][1]);
			}
		}
	}

	Int ans = 0;
	for (int i = 0; i < k; i++) {
		ans += max(dp[n - 1 - i][0], max(dp[n - 1 - i][1], dp[n - 1 - i][2]));
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
