#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int start = 1;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (start != a[i]) count++;
		if (count > 2) {
			cout << "NO" << '\n';
			return 0;
		}
		start++;
	}
	cout << "YES" << '\n';
	return 0;
}
