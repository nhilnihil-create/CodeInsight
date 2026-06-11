#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	double a, b, x;
	cin >> a >> b >> x;

	double v = a*a*b;
	double ans = 0;
	if (x >= 0.5*v){
		ans = atan(2.0 * (v - x) / (a*a*a));
	} else {
		ans = atan(a*b*b / (2.0*x));
	}

	double pi = atan(1.0) * 4.0;

	// 出力の桁数を細かくする
	cout << fixed << setprecision(10) << ans * 180.0 / pi << "\n";

	return 0;
}
