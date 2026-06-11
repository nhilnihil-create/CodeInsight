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
const int N = 200005;
//////////////////////////////

int h, w;
char s[111][111];
int dp[111][111];

void solve()
{
	cin >> h >> w;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> s[i][j];

	for (int i = 0; i <= h; i++) dp[i][0] = INF;
	for (int j = 0; j <= w; j++) dp[0][j] = INF;
	dp[1][1] = s[1][1] == '.' ? 0 : 1;

	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
			if (i == 1 && j == 1) continue;
			
			if (s[i][j] == '.') {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
			}
			else {
				dp[i][j] = min(dp[i - 1][j] + (s[i - 1][j] == '.'), dp[i][j - 1] + (s[i][j - 1] == '.'));
			}
		}
	cout << dp[h][w] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
