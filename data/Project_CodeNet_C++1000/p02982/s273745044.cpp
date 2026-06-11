#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, d; cin >> n >> d;
	vector<vector<int>> x(n, vector<int>(d));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			cin >> x[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= j) continue;
			int tmp = 0;
			for (int k = 0; k < d; k++) {
				tmp += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
			}
			for (int z = 1; z <= 1000; z++) {
				if (tmp == z * z) ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}