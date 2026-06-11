#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	int x, y; cin >> x >> y;
	int mx1 = x + y, mn1 = x + y;
	int mx2 = x - y, mn2 = x - y;
	while (--n) {
		cin >> x >> y;
		mx1 = max(mx1, x + y);
		mn1 = min(mn1, x + y);
		mx2 = max(mx2, x - y);
		mn2 = min(mn2, x - y);
	}
	cout << max(mx1 - mn1, mx2 - mn2) << '\n';
	return 0;
}
