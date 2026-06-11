#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int X;
	cin >> X;

	int mod = X % 100;
	int div = X / 100;
	if (mod == 0) {
		cout << "1" << endl;
		return 0;
	}

	int ans = 0;
	for (int i = 5; i >= 1; --i) {
		int tmpmod = mod % i;
		int tmpdiv = mod / i;

		if (div > tmpdiv) {
			if (tmpmod == 0) {
				ans = 1;
				break;
			}
			div -= tmpdiv;
			mod = tmpmod;
		}
		else  if (div == tmpdiv) {
			if (tmpmod == 0) {
				ans = 1;
			}
			break;
		}
		else {
			break;
		}
	}

	cout << ans << endl;
	return 0;
}
