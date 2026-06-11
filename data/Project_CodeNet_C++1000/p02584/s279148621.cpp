#include<iostream>
#include<cmath>

using namespace std;
using ll = long long;

int main() {
	ll x, k, d;
	cin >> x >> k >> d;
	x = abs(x);
	long long ido = x / d;
	if (ido > k) {
		cout << x - d * k << endl;
		return 0;
	}
	x = x - d * ido;
	k -= ido;
	if (k % 2 == 0) {
		cout << x << endl;
	}
	else {
		cout << d - x << endl;
	}
}