#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;
	long long sum = 0;
	for (int i = 0; i < m; i++) {
		long long x;
		cin >> x;
		sum += x;
		if (sum > n) {
			cout << -1;
			return 0;
		}
	}

	cout << n - sum;
}
