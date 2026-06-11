#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	if (n % 2 != 0) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 0;
	ll tmp = n / 2;
	while (0 < tmp) {
		ans += tmp / 5;
		tmp /= 5;		
	}
	cout << ans << endl;
	return 0;
}