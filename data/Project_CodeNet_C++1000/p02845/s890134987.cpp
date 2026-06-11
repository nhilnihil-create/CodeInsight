#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void) {
	int n, i, j, a[100003], s[3] = {}, t = 0, l, y;
	ll ans = 1;
	const int mod = 1e9 + 7;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (i = 0; i < n; i++) {
		l = 0;
		for (j = 0; j < 3; j++) {
			if (s[j] == a[i]) {
				if (l == 0) y = j;
				l++;
			}
		}
		if (l == 0) {
			cout << 0 << endl;
			return 0;
		}
		ans = ans * l % mod;
		s[y]++;
	}

	cout << ans << endl;

	return 0;
}