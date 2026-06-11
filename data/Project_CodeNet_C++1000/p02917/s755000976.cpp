#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<int> b(n + 1, 100001);
	for (int i = 1; i < n; i++) {
		cin >> b[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += min(b[i - 1], b[i]);
	}
	cout << ans << endl;
	return 0;
}