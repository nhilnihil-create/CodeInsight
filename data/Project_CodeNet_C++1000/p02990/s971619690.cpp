#include <iostream>
#include <string>
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
long long fac[200020], finv[200020], inv[200020];
long long mod = 1000000007;
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < 200020; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}
long long COM(long long n, long long k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
int main() {
	COMinit();
	long long n, k;
	cin >> n >> k;
	long long ans = 0;
	cout << n - k + 1 << endl;
	for (int i = 1; i < k; i++) {
		ans = COM(2 + (n - k) - 1, (n - k) - i) * COM(k - 1, i) % 1000000007;
		cout << ans << endl;
	}
}
