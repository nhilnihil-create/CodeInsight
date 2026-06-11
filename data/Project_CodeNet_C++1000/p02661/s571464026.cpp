#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	int a[n], b[n];
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

	sort(a, a + n); sort(b, b + n);

	if (n % 2 == 0) {
		int l = a[n / 2] + a[(n - 1) / 2], r = b[n / 2] + b[(n - 1) / 2];
		cout << 2 * (r / 2) - 2 * ((l + 1) / 2) + 1 + (l % 2) + (r % 2);	
	}
	else {
		cout << b[n / 2] - a[(n - 1) / 2] + 1;
	}
}
