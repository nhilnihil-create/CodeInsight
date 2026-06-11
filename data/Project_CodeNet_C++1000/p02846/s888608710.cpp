#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long T1, A1, B1, X1;
long long T2, A2, B2, X2;

int signs(long long val) {
	if (val > 0) return 1;
	if (val == 0) return 0;
	return -1;
}

int main() {
	cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
	X1 = T1 * (B1 - A1);
	X2 = T2 * (B2 - A2);

	if (X1 + X2 == 0) {
		cout << "infinity" << endl;
	}
	else if (signs(X1) == signs(X1 + X2)) {
		cout << "0" << endl;
	}
	else {
		long long V1 = -1LL * (X1 + X2);
		long long V2 = X1;
		if (V1 < 0) { V1 *= 1LL; V2 *= 1LL; }
		long long C = (V2 + V1) / V1; C *= 2LL; C -= 1LL;
		if (V2 % V1 == 0) C -= 1LL;
		cout << C << endl;
	}
	return 0;
}