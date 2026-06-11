#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll h; cin >> h;
	ll cnt = 0;
	while (0 < h) {
		cnt++;
		h /= 2;
	}
	ll ans = 1;
	ll tmp = cnt;
	while (tmp--) {
		ans *= 2;
	}
	cout << ans - 1 << endl;
    return 0;
}