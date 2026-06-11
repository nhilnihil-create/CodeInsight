// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100000, MD = 1000000007;

int dd[N];

int main() {
	int n, k; cin >> n >> k;
	if (n == 1) {
		cout << k << '\n';
		return 0;
	}
	long long ans = (long long) k * (k - 1) % MD;
	while (--n) {
		int i, j; cin >> i >> j, i--, j--;
		if (++dd[i] >= 2)
			ans = ans * (k - dd[i]) % MD;
		if (++dd[j] >= 2)
			ans = ans * (k - dd[j]) % MD;
	}
	cout << ans << '\n';
	return 0;
}
