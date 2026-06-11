#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;


int main() {
	int h, w;
	cin >> h >> w;

	vector<string> s(h + 1);
	for (int i = 1; i <= h; i++) {
		string si;
		cin >> si;
		s[i] = "#" + si;
	}

	s[0] = string('#', w + 1);

	vector<vector<int>> dp(h + 1, vector<int>(w + 1, BIG_NUM));
	dp[1][1] = 0;
	if (s[1][1] == '#') {
		dp[1][1]++;
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			int d1 = dp[i - 1][j];
			if (s[i][j] == '#' && s[i - 1][j] == '.') {
				d1++;
			}
			int d2 = dp[i][j - 1];
			if (s[i][j] == '#' && s[i][j - 1] == '.') {
				d2++;
			}

			dp[i][j] = min(dp[i][j], min(d1, d2));

		}
	}
	cout << dp[h][w] << endl;
}