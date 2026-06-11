#include <bits/stdc++.h>
using namespace std;

int t[2];
long long a[2], b[2], x, y;

int main() {
	cin >> t[0] >> t[1] >> a[0] >> a[1] >> b[0] >> b[1];
	x = (a[0] - b[0]) * t[0];
	y = (a[1] - b[1]) * t[1];

	if (x + y == 0)
		cout << "infinity" << endl;
	else if ((x > 0) ^ (x + y > 0))
		cout << -x / (x + y) + (abs(y) - 1) / abs(x + y) << endl;
	else
		cout << 0 << endl;
}
