#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n), b(n), c(n - 1);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n - 1; i++) cin >> c[i];
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += b[a[i] - 1];
		if (a[i] + 1 == a[i + 1]) {
			sum += c[a[i] - 1];
		}
	}
	cout << sum << '\n';
}
