#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int m, d; cin >> m >> d;
	int ans = 0;
	for (int i = 4; i <= m; i++) {
		for (int j = 22; j <= d; j++) {
			int d1 = j % 10;
			int d2 = j / 10;
			if (d1 < 2 || d2 < 2) continue;
			if (d1 * d2 == i) {
				ans++;
				//cout << i << " " << j << endl;
			}
		}
	}
	cout << ans << endl;
	return 0;
}