#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using VI = vector<int>;
using PI = pair<int, int>;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double s = 0.5 * a * b * sin(M_PI * c / 180);
	cout << setprecision(8) << fixed << s << '\n'
	 << a + b + sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(M_PI * c / 180)) << '\n'
	 << 2 * s / a << endl;
	return 0;
}

