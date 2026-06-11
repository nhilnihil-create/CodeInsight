#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
const int N = 100001;

int main () {
	ll t1, t2, a1, a2, b1, b2; cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
	ll a = t1*(a1-b1), b = t2*(a2-b2);
	if (a > 0)
		a *= -1LL, b *= -1LL;
	if (a+b < 0) {
		cout << 0 << endl;
	} else if (a+b == 0) {
		cout << "infinity" << endl;
	} else {
		ll s = -a/(a+b), t = abs(a)%(abs(a+b));
		cout << 2LL*s+(t != 0) << endl; 
	}

	return 0;
}