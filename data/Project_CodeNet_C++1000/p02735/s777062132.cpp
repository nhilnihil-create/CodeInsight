#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
#include <queue>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
template<typename T1, typename T2>
inline void chmin(T1& a, T2 b){if (a > b) a = b;}
template<typename T1, typename T2>
inline void chmax(T1& a, T2 b){if (a < b) a = b;}
const ll MOD = 1000000007;
const ll INF = 1LL << 60;

int dp[110][110];
char s[110][110];


int main()
{
	int H, W;
	cin >> H >> W;

	rep(i, H) {
		rep(j, W) {
			cin >> s[i][j];
		}
	}

	//大きな数で初期化
	rep(i, H+1) {
		rep(j, W+1) {
			dp[i][j] = (1 << 25);
		}
	}

	//初期条件
	if (s[0][0] == '#') dp[0][0] = 1;
	else dp[0][0] = 0;

	rep(i, H) {
		rep(j, W) {
			if (s[i][j] == '#') {
				if (s[i][j + 1] == '#') chmin(dp[i][j+1], dp[i][j]);
				else chmin(dp[i][j + 1], dp[i][j]);
			}
			else {
				if (s[i][j + 1] == '#') chmin(dp[i][j + 1], dp[i][j] + 1);
				else chmin(dp[i][j + 1], dp[i][j]);
			}

			if (s[i][j] == '#') {
				if (s[i + 1][j] == '#') chmin(dp[i + 1][j], dp[i][j]);
				else chmin(dp[i + 1][j], dp[i][j]);
			}
			else {
				if (s[i + 1][j] == '#') chmin(dp[i + 1][j], dp[i][j] + 1);
				else chmin(dp[i + 1][j], dp[i][j]);
			}

		}
	}
	
	/*rep(i, H) {
		rep(j, W) {
			cout  << dp[i][j] << " ";
		}
		cout << endl;
	}*/

	cout << dp[H-1][W-1] << endl;
	
}