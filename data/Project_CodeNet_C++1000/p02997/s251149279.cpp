// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int n, k; cin >> n >> k;
	if (k > (n - 1) * (n - 2) / 2) {
		cout << "-1\n";
		return 0;
	}
	int m = n - 1 + (n - 1) * (n - 2) / 2 - k;
	cout << m << '\n';
	for (int i = 1; i < n; i++)
		cout << i << ' ' << n << '\n';
	m -= n - 1;
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			if (m-- == 0)
				return 0;
			cout << i << ' ' << j << '\n';
		}
	return 0;
}
	