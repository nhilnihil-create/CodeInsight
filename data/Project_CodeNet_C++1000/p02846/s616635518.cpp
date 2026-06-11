#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

ll t1, t2, a1, a2, b1, b2;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
	a1 *= t1, a2 *= t2, b1 *= t1, b2 *= t2;
	if (a1 + a2 == b1 + b2) {
		cout << "infinity";
		return 0;
	} else if ((a1 > b1 && a2 > b2) || (a1 < b1 && a2 < b2)) {
		cout << 0;
		return 0;
	} else { 
		if (llabs(a2 - b2) < llabs(a1 - b1)) {
			cout << "0";
			return 0;
		}
		
		ll dist = llabs(a1 - b1);
		ll gain = llabs(llabs(a1 - b1) - llabs(a2 - b2));
		ll ans = ceil((long double)dist / gain) * 2ll;
		if (dist % gain) --ans;
		cout << ans;
	}
}
