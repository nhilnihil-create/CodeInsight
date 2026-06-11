#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	if (a % 2 == b % 2)
		cout << (b - a) / 2 << endl;
	else {
		ll p = a + (b - a) / 2, q = n - b + 1 + (b - a) / 2;
		cout << min(p, q) << endl;
	}
	return 0;
}