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

#define int long long

const int MOD = 1e9 + 7;

int add(int a, int b) {
	return (a + b) % MOD;
}

int mul(int a, int b) {
	return (a * b) % MOD;
}

int binpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int n = (int)s.size();
	int pc = 0;
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		if (i == n || s[i] == '1') {
			int other = binpow(3, max((int)0, n - i - 1));
			other = mul(other, binpow(2, pc));
			ans = add(ans, other);
			pc++;
		}
	}
	cout << ans << endl;
}
