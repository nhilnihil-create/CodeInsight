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

int mul(int a, int b) {
	return 1LL * a * b % MOD;
}

int add(int a, int b) {
	return (a + b) % MOD;
}

int sub(int a, int b) {
	return (a - b + MOD) % MOD;
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

	int n;
	cin >> n;
	int ans = binpow(10, n);
	{
		int c = 0;
		for (int i = 0; i < n; i++) {
			c = add(c, mul(binpow(8, i), binpow(9, n - 1 - i)));
		}
		c = mul(c, 2);
		ans = sub(ans, c);
	}
	ans = sub(ans, binpow(8, n));
	cout << ans << '\n';
}