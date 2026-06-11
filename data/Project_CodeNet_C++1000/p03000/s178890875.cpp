#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans = 1, sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum <= x) ans++;
	}
	cout << ans << '\n';
}
