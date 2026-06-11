#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c;
	int k;
	cin >> a >> b >> c >> k;

	int x, z;

	x = k - a;
	z = x - b;

	if (k <= a) {
		cout << k;
	}
	else if (x <= b) {
		cout << a;
	}
	else if (z > 0) {

		cout <<a + (-1 * z);
	}else {
             cout << a;
	}
}