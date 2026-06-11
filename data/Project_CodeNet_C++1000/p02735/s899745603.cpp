#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <cmath>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;
ll dx[] = { 1,0 };
ll dy[] = { 0,1 };

int main() {

    ll H, W;
	cin >> H >> W;

    vector<vector<char>>s(100, vector<char>(100));

	rep(i, H) {
		rep(j, W) {
			cin >> s[i][j];
		}
	}

    vector<vector<ll>> dp(H, vector<ll>(W, mod));

    dp[0][0] = 0;
    if (s[0][0] == '#') dp[0][0]++;

    for (ll i = 0; i < H; i++) {
        for (ll j = 0; j < W; j++) {
            for (ll k = 0; k < 2; k++) {
                ll nx = j + dx[k];
                ll ny = i + dy[k];
                if (ny >= H || nx >= W) continue;
                if (s[i][j] == '.' && s[ny][nx] == '#') dp[ny][nx] = min(dp[ny][nx], dp[i][j] + 1);
                else dp[ny][nx] = min(dp[ny][nx], dp[i][j]);
            }
        }
    }

    cout << dp[H - 1][W - 1] << endl;


	return 0;
}