#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int h, w;
	cin >> h >> w;
	if (h == 1 || w == 1) {
		cout << 1 << '\n';
		return 0;
	}
	long long ans = 0;
	for (int i = 1; i <= h; i++) {
		if (i % 2 == 1) {
			if (w % 2 == 0) {
				ans += (w / 2);
			} else {
				ans += (w / 2) + 1;
			}
		} else {
			ans += (w / 2);
		}
	}
	cout << ans << '\n';
	
	return 0;
}
