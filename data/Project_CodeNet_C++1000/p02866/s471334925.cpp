#define MOD 998244353

#include <iostream>
#include <vector>
using namespace std;

long pow(long a, long b) {
	if (!b) return 1;
	long c = pow(a, b / 2);
	if (b % 2) c = a * c % MOD * c % MOD;
	else c = c * c % MOD;
	return c;
}

int main() {
	int N;
	cin >> N;
	vector<int> D(N);
	for (int& i : D) cin >> i;
	if (D.front()) {
		cout << 0;
		return 0;
	}
	vector<long> a(N);
	for (int& i : D) a[i]++;
	if (a.front() != 1) {
		cout << 0;
		return 0;
	}
	while (!a.back()) a.pop_back();
	long ans = 1;
	for (int i = 1; i < a.size(); i++) {
		ans *= pow(a[i - 1], a[i]);
		ans %= MOD;
	}
	cout << ans;
}