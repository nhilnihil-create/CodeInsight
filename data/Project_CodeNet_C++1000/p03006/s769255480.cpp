#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n; cin >> n;
	vector<ll> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	ll maxCnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			ll tmp_x = x[j] - x[i];
			ll tmp_y = y[j] - y[i];
			ll tmpCnt = 0;
			for (int k = 0; k < n; k++) {
				for (int h = 0; h < n; h++) {
					if (k == h) continue;
					if (x[h] - x[k] == tmp_x && y[h] - y[k] == tmp_y) {
						tmpCnt++;
					}
				}
			}
			maxCnt = max(maxCnt, tmpCnt);
		}
	}
	cout << n - maxCnt << endl;
	return 0;
}