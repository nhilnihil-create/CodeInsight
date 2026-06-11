#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}	
	for (int i = 0; i < k; i++) {
		vector<int> b(n + 1, 0);
		for (int j = 0; j < n; j++) {
			int l = max(0, j - a[j]);
			int r = min(n, j + a[j] + 1);
			b[l]++;
			b[r]--;
		}
		vector<int> accum(n + 1, 0);
		for (int j = 0; j < n; j++) {
			accum[j] += b[j];
			if (0 < j) {
				accum[j] += accum[j - 1];
			}
		}
		if (accum == a) break;
		a = accum;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}