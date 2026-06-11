#include <iostream>

using namespace std;
using ll = long long;

int main() {
	int X;
	cin >> X;

	ll ans = X;
	if (ans == 2) {
		cout << ans << endl;
		return 0;
	}

	if (X % 2 == 0) {
		ans += 1;
	}

	while (true) {
		for (int i = 3; ; i += 2) {
			if (i >= ans) {
				cout << ans << endl;
				return 0;
			}
			if (ans % i == 0) {
				break;
			}
		}
		ans += 2;
	}
	return 0;
}
