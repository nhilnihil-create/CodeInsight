#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;
const LL p = 1e9 + 7;
LL n, k;
LL cnt[100005];

LL modpow(LL a, LL n) {
	if (n == 0) return 1;
	if (n % 2) return ((a%p) * (modpow(a, n - 1) % p)) % p;
	return modpow((a*a) % p, n / 2) % p;
}

int main() {
	cin >> n >> k;
	for (LL i = k; i >= 1; i--) {
		LL num = k / i;
		cnt[i] = modpow(num, n);
		for (LL j = 2 * i; j <= k; j += i) {
			cnt[i] += p - cnt[j];
			if (cnt[i] >= p) cnt[i] -= p;
		}
	}

	LL res = 0;
	for (LL i = 1; i <= k; i++) res = (res + i * cnt[i] % p) % p;
	cout << res << endl;

	return 0;
}