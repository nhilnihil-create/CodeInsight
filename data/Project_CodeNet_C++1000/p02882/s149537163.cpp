#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cout.precision(16);
	double a, b, x;
	cin >> a >> b >> x;
	if (2 * x < a * a * b) {
		cout << atan(a * b * b / 2 / x) * 180 / M_PI << endl;
	}
	else {
		cout << atan(2 / a * (b - x / a / a)) * 180 / M_PI << endl;
	}
}
