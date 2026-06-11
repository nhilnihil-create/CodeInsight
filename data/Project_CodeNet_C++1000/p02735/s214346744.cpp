#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <assert.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// AGC043-A, 1012, 18:00(UNSOLVED), 
	int h, w; cin >> h >> w;
	vector<string> mp(h);
	rep(i, h) cin >> mp[i];
	vector<vector<int>> dp(h, vector<int>(w, iINF));
	dp[0][0] = mp[0][0] == '#' ? 1 : 0;
	rep(i, h) {
		rep(j, w) {
			if (j != 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + (mp[i][j - 1] != mp[i][j]));
			if (i != 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + (mp[i - 1][j] != mp[i][j]));
		}
	}
	if (mp[h - 1][w - 1] == '#') dp[h - 1][w - 1]++;
	cout << dp[h - 1][w - 1] / 2 << endl;
	return 0;
}