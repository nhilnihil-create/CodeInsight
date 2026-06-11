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

int n;
Int dp[N][13];
string s;

void solve()
{
	cin >> s;
	n = s.size();
	if (s[0] == '?') {
		for (int j = 0; j < 10; j++) dp[1][j] = 1;
	}
	else {
		dp[1][s[0] - '0'] = 1;
	}

	for (int i = 1; i < n; i++) {
		if (s[i] != '?') {
			int tmp = s[i] - '0';
			for (int j = 0; j < 13; j++) {
				(dp[i + 1][(tmp + 10 * j) % 13] += dp[i][j]) %= MOD;
			}
		}
		else {
			for (int tmp = 0; tmp < 10; tmp++) {
				for (int j = 0; j < 13; j++) {
					(dp[i + 1][(tmp + 10 * j) % 13] += dp[i][j]) %= MOD;
				}
			}
		}		
	}

	cout << dp[n][5] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
