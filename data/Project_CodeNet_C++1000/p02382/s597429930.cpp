#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double PI = 3.1415926535;

int main() {
	// 小数点以下12ケタを表示させるためのおまじない
	cout << fixed << setprecision(12);

	int n;
	cin >> n;

	int x[1000], y[1000];
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}

	double man = 0.0, euc = 0.0, san = 0.0, che = 0.0;
	for (int i = 0; i < n; i++) {
		double diff = abs(x[i] - y[i]);
		man += diff;
		euc += pow(diff, 2);
		san += pow(diff, 3);
		che = (che < diff) ? diff : che;
	}
	euc = sqrt(euc);
	san = cbrt(san);

	cout << man << endl;
	cout << euc << endl;
	cout << san << endl;
	cout << che << endl;
	return 0;
}

