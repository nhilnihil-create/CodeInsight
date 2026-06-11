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
#include <chrono>
#include <random>
#include <functional>

using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b) {
	return (a + b) % MOD;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> dp(n + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j + 3 <= i; j++) {
			dp[i] = add(dp[i], dp[j]);
		}
	}
	cout << dp[n] << '\n';
}