#include <bits/stdc++.h>
using namespace std;

double a, b;

int main() {
	cin >> a >> b;
	double x = ceil(a / 0.08);
	while ((int) (x * 0.08) == a) {
		if ((int) (x * 0.1) == b) {
			cout << x << '\n';
			return 0;
		}
		x++;
	}
	cout << -1 << '\n';
}