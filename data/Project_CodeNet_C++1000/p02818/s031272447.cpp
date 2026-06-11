#include <iostream>

using namespace std;
using ll = long long;

int main() {
	ll A, B, K;
	cin >> A >> B >> K;

	ll ans = 0;
	if (A > K) {
		A -= K;
	}
	else {
		K -= A;
		A = 0;
		if (B > K) {
			B -= K;
		}
		else {
			K -= B;
			B = 0;
		}
	}

	cout << A << " " << B << endl;

	return 0;
}

