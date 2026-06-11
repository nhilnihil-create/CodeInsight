#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n, k; cin >> n >> k;	
	vector<int> accum(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int p; cin >> p;
		accum[i] += p + 1;
		accum[i] += accum[i - 1];
	}
	int ans = 0;
	for (int i = 1; i <= n - k + 1; i++) {
		int tmp = accum[i + k - 1] - accum[i - 1];
		ans = max(ans, tmp);
	}
	cout << fixed << setprecision(11) << (double)ans / 2 << endl;
	return 0;
}