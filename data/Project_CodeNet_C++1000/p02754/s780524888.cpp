#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {

	ll n, a, b;
	cin >> n >> a >> b;

	if (a == 0) {
		cout << 0 << endl;
		return 0;
	}

	if (b == 0) {
		cout << n << endl;
		return 0;
	}


	ll ans = 0;
	ll count = 0;
	ll c = a + b;

	ll re = n / c;

	ans = a*re;
	count = c*re;
	n -= c*re;

	if (n < a) {
		cout << ans + n << endl;
		return 0;
	}
	else {
		cout << ans + a << endl;
		return 0;
	}


	return 0;
}