#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int t = 7;
	for (int i=1; i<=n; i++) {
		if (t % n == 0) {
			cout << i;
			return 0;
		}
		else {
			t *= 10;
			t += 7;
			t %= n;
		}
	}
	cout << -1;
}
