#include "bits/stdc++.h"
using namespace std;

int main() {
	long long T1, T2;
	cin >> T1 >> T2;
	long long A1, A2, B1, B2;
	cin >> A1 >> A2 >> B1 >> B2;
	long long X = (A1 - B1)*T1;
	long long Y = (A2 - B2)*T2;
	if (X > 0) {
		X = -1 * X;
		Y = -1 * Y;
	}
	if (0 == (X + Y)) {
		cout << "infinity" << endl;
		return 0;
	}
	if (0 > (X + Y)) {
		cout << 0 << endl;
		return 0;
	}
	long long ans = 0;
	ans = (-1 * X) / (X + Y);
	ans *= 2;
	if (0 == (-1*X)%(X+Y)) {
		ans--;
	}
	ans++;
	cout << ans << endl;
	return 0;
}

