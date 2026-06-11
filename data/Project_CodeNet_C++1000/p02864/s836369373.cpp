#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>

using namespace std;

#define int long long

const int INF = 1e18 + 239;
const int N = 3003;

int dp[N][N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = INF;
		}
	}
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &t : a) {
		cin >> t;
	}
	a.insert(a.begin(), 0);
	a.push_back(0);
	n += 2;
	dp[0][0] = 0;
	for (int i = 0; i + 1 < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int ln = 0; i + ln + 1 < n; ln++) {
				dp[i + ln + 1][j + ln] = min(dp[i + ln + 1][j + ln], dp[i][j] + abs(a[i] - a[i + ln + 1]));
			}
		}
	}
	cout << dp[n - 1][k] / 2 << endl;
}
