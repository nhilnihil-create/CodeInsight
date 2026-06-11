#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> x(n, -1);	
	for (int i = 0; i < m; i++) {
		int s, c;
		cin >> s >> c;
		s--;
		if (x[s] != -1 && x[s] != c) {
			cout << -1 << endl;
			return 0;
		}
		x[s] = c;
	}
	if (n > 1 && x[0] == 0) {
		cout << -1 << endl;
		return 0;
	}
	if (n > 1 && x[0] == -1) x[0] = 1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans *= 10;
		ans += max(0, x[i]);
	}
	cout << ans << endl;
	return 0;
}