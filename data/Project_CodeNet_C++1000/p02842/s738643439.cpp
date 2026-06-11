#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		double ans = i * 1.08;
		if ((int) ans == n) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << ":(" << '\n';
	
	return 0;
}
