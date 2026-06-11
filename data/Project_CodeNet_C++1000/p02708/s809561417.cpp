#include <iostream>
#include <vector>
#include <map>
using namespace std;

const long MOD = 1'000'000'007;

int main() {
	long n, k; cin >> n >> k;
	long ans = 0;
	for (long i = k; i <= n+1; i++) {
		long min = i * (i - 1) / 2;
		long max = i * (n * 2 - i + 1) / 2;
		ans += (max - min + 1) % MOD;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
