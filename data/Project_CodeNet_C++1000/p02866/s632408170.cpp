#define MOD 998244353

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long pow(long a, long b) {
	if (b == 0) return 1;
	long c = pow(a, b / 2);
	if (b % 2) c = a * c % MOD * c % MOD;
	else c = c * c % MOD;
	return c;
}

int main() {
	int N;
	cin >> N;
	vector<long> D(N), a(N);
	for (long& i : D) {
		cin >> i;
		a[i]++;
	}
	if (!D.front() && count(D.begin(), D.end(), 0) == 1) {
		sort(D.begin(), D.end());
		bool b = true;
		for (int i = 1; i < N; i++) {
			if (1 < abs(D[i - 1] - D[i])) {
				b = false;
				break;
			}
		}
		if (b) {
			long ans = 1;
			for (int i = 2; i < N; i++) {
				ans *= pow(a[i - 1], a[i]);
				ans %= MOD;
			}
			cout << ans;
		}
		else cout << 0;
	}
	else cout << 0;
}