#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <fstream>
#include <bitset>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;
const long long MOD = 1000000007LL;
const long long MAX = 500000LL;
using namespace std;
typedef unsigned long long ull;
typedef  long long ll;

int main()
{
	string s, t;
	cin >> s >> t;
	vector<vector<ll>> dp(s.size() + 1, vector<ll>(t.size() + 1, INF));

	for (ll i = 0; i <= s.size(); i++) {
		dp[i][0] = i;
	}

	for (ll j = 0; j <= t.size(); j++) {
		dp[0][j] = j;
	}

	for (ll i = 0; i < s.size(); i++) {
		for (ll j = 0; j < t.size(); j++) {
			if (s[i] == t[j]) {
				chmin(dp[i + 1][j + 1], dp[i][j]);
			}
			else {
				chmin(dp[i + 1][j + 1], dp[i][j] + 1);
				chmin(dp[i + 1][j + 1], dp[i + 1][j] + 1);
				chmin(dp[i + 1][j + 1], dp[i][j + 1] + 1);
			}
		}
	}

	cout << dp[s.size()][t.size()] << endl;
	return 0;
}

