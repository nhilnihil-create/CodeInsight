#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
long long fac[700040], finv[700040], inv[700040];
void cominit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < 700040; i++) {
		fac[i] = fac[i - 1] * i % 1000000007;
		inv[i] = 1000000007 - inv[1000000007 % i] * (1000000007 / i) % 1000000007;
		finv[i] = finv[i - 1] * inv[i] % 1000000007;
	}
}
long long com(long long n, long long k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % 1000000007) % 1000000007;
}

int main() {
	long long x, y;
	long long a, b;
	cin >> x >> y;
	long long ans = 1;
	if ((x + y) % 3 == 0) {
		a = 0, b = 0;
		a = (2 * x - y) / 3;
		b = (2 * y - x) / 3;
	}
	else {
		cout << "0" << endl;
		return 0;
	}
	cominit();
	cout << com(a + b, a) << endl;
	return 0;
}