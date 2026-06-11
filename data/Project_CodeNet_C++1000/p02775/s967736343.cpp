#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef complex<ld> com;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000010;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }

int dp[1000010][2];

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	string s;
	cin >> s;
	reverse(all(s)); 
	int n = s.size();
	rep(i, n + 1) rep(j, 2) dp[i][j] = inf;
	dp[0][0] = 0;
	rep(i, n) {
		int c = s[i] - '0';
		chmin(dp[i + 1][0], dp[i][0] + c);
		chmin(dp[i + 1][0], dp[i][1] + c + 1);
		chmin(dp[i + 1][1], dp[i][0] + 10 - c);
		chmin(dp[i + 1][1], dp[i][1] + 9 - c);
	}
	cout << min(dp[n][0], dp[n][1] + 1) << '\n';
}