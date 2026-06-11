#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	string stones;
	cin >> n >> stones;

	int r = 0;
	for (int i = 0; i < n; i++) {
		if (stones.at(i) == 'R') r++;
	}

	int ans = 0;
	for (int i = 0; i < r; i++) {
		if (stones.at(i) == 'W') ans++;
	}

	cout << ans << endl;
}