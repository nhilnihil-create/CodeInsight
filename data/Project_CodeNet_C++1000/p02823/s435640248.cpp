#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long N, A, B;

int main() {
	cin >> N >> A >> B;
	if ((A - B + (1LL << 60)) % 2 == 0) {
		cout << abs(A - B) / 2LL << endl;
	}
	else {
		// パターン 1
		long long S1 = 1, S2 = B - A;
		long long S3 = A, S4 = (S2 - S1) / 2LL;

		// パターン 2
		long long T1 = A + (N + 1LL - B), T2 = N;
		long long T3 = (N + 1LL - B), T4 = (T2 - T1) / 2LL;

		cout << min(S3 + S4, T3 + T4) << endl;
	}
	return 0;
}