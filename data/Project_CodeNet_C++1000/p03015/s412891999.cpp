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
#define LINF ((Int)1<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P; 
const int N = 100005;
//////////////////////////////

string L;
int n;
Int dp[N][2];

void solve()
{
	cin >> L;
	n = L.size();
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		//equal
		if (L[i] == '0') dp[i + 1][0] += dp[i][0];
		else dp[i + 1][0] += (2 * dp[i][0]);
		dp[i + 1][0] %= MOD;

		//less
		dp[i + 1][1] += (3 * dp[i][1]);
		if (L[i] == '1') dp[i + 1][1] += dp[i][0];
		dp[i + 1][1] %= MOD;
	}

	cout << (dp[n][0] + dp[n][1]) % MOD << endl;

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
