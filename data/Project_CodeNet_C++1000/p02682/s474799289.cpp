#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, n;
	cin >> a >> b >> c >> n;

	int sum = 0;

	if (n >= a) { sum += a; n -= a;
		if (n >= b) { n -= b; } {
			if (n) sum -= n;
		}
	}
	else sum += n;

	cout << sum;
}
