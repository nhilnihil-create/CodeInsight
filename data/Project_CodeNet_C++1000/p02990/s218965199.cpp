#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

const int mod = 1e9 + 7;
vector<long long int> fac;
long long int mypow(long long int a, long long int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	long long int res = mypow(a, b / 2);
	res = res * res % mod;
	if (b % 2 == 1) res = res * a % mod;
	return res;
}

long long int myc(long long int a, long long int b) {
	return fac[a] * mypow(fac[b], mod - 2) % mod * mypow(fac[a - b], mod - 2) % mod;
}

int main() {
	long long int n, k;
	cin >> n >> k;
	fac.push_back(1);
	for (int i = 1; i <= n + 1; i++) {
		fac.push_back(fac.back() * i % mod);
	}
	for (int i = 1; i <= k; i++) {
		if (n - k - (i - 1) < 0) {
			cout << 0 << endl;
			continue;
		}
		cout << myc(k - 1, i - 1) * myc(n - k - (i - 1) + i, i) % mod << endl;
	}
}
