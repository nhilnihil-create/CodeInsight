#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int sum = 0;
	for (int i = 0; i < n; i++) sum += a[i];
	int sum2 = 0;
	int ans = 1e9;
	for (int i = 0; i < n; i++) {
		sum2 += a[i];
		ans = min(ans, abs((sum - sum2) - sum2));
	}
	cout << ans << '\n';
}
