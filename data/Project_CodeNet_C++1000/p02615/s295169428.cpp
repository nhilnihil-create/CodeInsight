#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> player(n);
	for (auto &e : player) {
		cin >> e;
	}
	
	sort(player.rbegin(), player.rend());

	long long int ans = 0;
	for (int k = 1; k < n; k++) {
		ans += player[floor(k / 2)];
	}

	cout << ans << endl;
}