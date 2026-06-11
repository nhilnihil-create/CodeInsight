#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll a, b; cin >> a >> b;
	if (b == 1) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1;
	ll tap = a;
	while (tap < b) {
		ans++;
		tap += a - 1;
	}
	cout << ans << endl;
	return 0;
}