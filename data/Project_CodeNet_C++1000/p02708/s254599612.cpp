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

	long long  n, k; cin >> n >> k;
	vector<long long > pref(n + 1, 0);
	iota(pref.begin(), pref.end(), 0);
	for (long long  i = 1; i <= n; i++) pref[i] += pref[i - 1];

	Modint ans = 1;
	for (long long  i = k; i <= n; i++) {
		long long  left = pref[i - 1] - pref[0];
		long long  right = pref[n] - pref[n - i];

		ans += Modint(right - left + 1);
	}

	cout << ans;

	return 0;
}