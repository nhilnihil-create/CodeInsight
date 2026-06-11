#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ll a, b, c, d; cin >> a >> b >> c >> d;
	ll l = c / __gcd(c, d) * d;
	ll e = b - b / c - b / d + b / l;
	ll f = ~- a - ~- a / c - ~- a / d + ~- a / l;
	cout << e - f << endl;
	return 0;
}
