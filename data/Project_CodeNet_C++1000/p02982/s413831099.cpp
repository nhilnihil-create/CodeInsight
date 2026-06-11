#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> v(n, vector<int> (k));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> v[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int w = i + 1; w < n; ++w) {
			int x = 0;
			for (int j = 0; j < k; ++j) {
				x += abs(v[i][j] - v[w][j]) * abs(v[i][j] - v[w][j]);
			}
			int e = sqrt(x);
			//cout << e << " " << x << " " << i << " " << w << endl;
			if (e * e == x) {
				cnt++;
			}
		}
	}
	cout << cnt;
}

















