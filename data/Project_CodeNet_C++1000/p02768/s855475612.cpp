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
long long int mypow(long long int a, long long int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	long long int res = mypow(a, b / 2);
	res = res * res % mod;
	if (b % 2 == 1) res = res * a % mod;
	return res;
}

long long int range_product(long long int a, long long int b) {
	long long int res = 1;
	for (int i = a; i <= b; i++) {
		res *= i;
		res %= mod;
	}
	return res;
}

long long int myc(long long int a, long long int b) {
	long long int r1 = range_product(a - b + 1, a);
	long long int r2 = range_product(1, b);
	return r1 * mypow(r2, mod - 2) % mod;
}

int main() {
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	long long int res = mypow(2, n) - 1;
	res -= myc(n, a);
	res -= myc(n, b);
	
	res %= mod;
	res += mod;
	res %= mod;
	cout << res << endl;
}
