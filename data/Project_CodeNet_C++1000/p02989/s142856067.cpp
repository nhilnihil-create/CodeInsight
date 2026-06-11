#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> d(n);
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	sort(d.begin(), d.end());
	int ans = d[n / 2] - d[n / 2 - 1];
	cout << ans << '\n';	
	
	return 0;
}
