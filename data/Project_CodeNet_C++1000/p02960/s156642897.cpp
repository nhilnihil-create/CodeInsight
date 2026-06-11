#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const int INF = 1000000000;
const double PI = 3.1415926535897932;
const ll MOD = 1000000007;

const int N = 13;
ll dp[100001][N] = { 0 };

int main()
{
	string s;
	cin >> s;

	dp[0][0] = 1;
	int mul = 1;
	for (int i = 0; i < s.size(); i++) {
		char c = s[s.size()-1-i];
		if (c == '?') {
			rep(k, 10) rep(j, N) {
				dp[i+1][(k * mul + j) % N] += dp[i][j];
				dp[i+1][(k * mul + j) % N] %= MOD;
			}
		}
		else {
			int k = c - '0';
			rep(j, N) {
				dp[i + 1][(k * mul + j) % N] += dp[i][j];
				dp[i + 1][(k * mul + j) % N] %= MOD;
			}
		}
		mul = (mul * 10) % N;
	}
	cout << dp[s.size()][5] << endl;
	return 0;
}