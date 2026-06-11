#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <utility>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <unordered_map>

using namespace std;
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

const int MOD = 1e9 + 7;
class Modint {
public:
	long long val;

	Modint (long long _val = 0)
		: val((_val + MOD) % MOD) {}

	Modint operator+ (Modint other) {
		return Modint(val + other.val);
	}

	void operator+= (Modint other) {
		val += other.val;
		val %= MOD;
	}

	Modint operator- () {
		return Modint(MOD - val);
	}

	Modint operator- (Modint other) {
		return Modint(val + MOD - other.val);
	}

	void operator-= (Modint other) {
		val += MOD - other.val;
		val %= MOD;
	}

	Modint operator* (Modint other) {
		return Modint(val * other.val);
	}

	void operator*= (Modint other) {
		val *= other.val;
		val %= MOD;
	}

	bool operator== (Modint other) {
		return val == other.val;
	}

	bool operator!= (Modint other) {
		return val != other.val;
	}
};

Modint exp (Modint a, int k) {
	if (k == 0) {
		return Modint(1);
	} else if (k % 2 == 0) {
		Modint half = exp(a, k / 2);
		return half * half;
	} else {
		return a * exp(a, k - 1);
	}
}

Modint inv (Modint a) {
	return exp(a, MOD - 2);
}

ostream& operator<< (ostream& out, Modint p) {
	out << p.val;
	return out;
}


int main() {

	int n, m; cin >> n >> m;
	vector<bool> broken(n + 1, false);
	for (int i = 1; i <= m; i++) {
		int a; cin >> a;
		broken[a] = true;
	}

	vector<Modint> dp(n + 1, 0);
	dp[0] = 1, dp[1] = (broken[1] == false);

	for (int i = 2; i <= n; i++) {
		if (broken[i]) continue;
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];


	return 0;
}