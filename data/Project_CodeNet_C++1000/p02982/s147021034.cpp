#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N, D;
	cin >> N >> D;

	vector<vector<int>> X(N, vector<int>(D));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < D; j++) {
			cin >> X[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			int dist2 = 0;
			for (int k = 0; k < D; ++k) {
				dist2 += ((X[i][k] - X[j][k]) * (X[i][k] - X[j][k]));
			}

			int k = 1;
			while (k <= dist2) {
				if (dist2 % k == 0 && dist2 / k == k) {
					ans++;
				}
				k++;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
