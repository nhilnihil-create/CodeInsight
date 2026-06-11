#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	LL a, b, k;
	cin >> a >> b >> k;
	if (a >= k) {
		cout << (a - k) << ' ' << b << '\n';
	} else if (a + b >= k) {
		cout << 0 << ' ' << (b - (k - a)) << '\n';
	} else {
		cout << "0 0\n";
	}
	return 0;
}
