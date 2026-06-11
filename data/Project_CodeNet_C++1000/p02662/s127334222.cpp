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
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;

//typedef modint998244353 mint;

const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
//const ll MOD = 1e9 + 7;
const ll MOD = 998244353;
const double EPS = 1e-7;
const double MAX = 1000 + 5;


int main() {
	int n, s;
	cin >> n >> s;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<vector<int>> dp(n + 1, vector<int>(s + 1));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		

		for (int j = 0; j <= s; j++) {
			dp[i + 1][j] = (2 * dp[i][j]) % MOD;
			if (j < a[i]) {
				continue;
			}

			dp[i + 1][j] += dp[i][j - a[i]];
			dp[i + 1][j] %= MOD;
		
			
		}
		/*
		for (int d : dp[i+1]) {
			cout << d << " ";
		}
		cout << endl;
		*/
	}

	cout << dp[n][s] << endl;
}