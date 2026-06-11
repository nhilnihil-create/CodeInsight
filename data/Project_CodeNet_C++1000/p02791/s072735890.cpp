#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, p;
	cin >> n;

	int ans = 0, min = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> p;
		if (p < min) {
			ans++;
			min = p;
		}
	}
	cout << ans << endl;
}