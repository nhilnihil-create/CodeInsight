#include <iostream>
using namespace std;

const int mxN = 2e5 + 5;
long long a[mxN], cnt[mxN];

int main() {
	int n;
	cin >> n;
	long long tot = 0;
	for(int i = 1; i <= n; ++i)
		cin >> a[i], ++cnt[a[i]];
	for(int i = 1; i <= n; ++i) {
		tot += (cnt[i] * (cnt[i] - 1) / 2);
	}
	for(int i = 1; i <= n; ++i) {
		long long temp = cnt[a[i]] - 1;
		cout << tot - cnt[a[i]] * (cnt[a[i]] - 1) / 2 + temp * (temp - 1) / 2 << '\n';
	}
	// inclusion exclusion
}
