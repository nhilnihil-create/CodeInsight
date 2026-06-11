#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long long A1, A2, B1, B2, T1, T2, D1, D2, D3, p, q;
	cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
	D1 = (A1 - B1) * T1;
	D2 = (A2 - B2) * T2;

	if (D1 < 0) {
		D1 *= -1; D2 *= -1;
	}
	if (D1 + D2 > 0) {
		cout << 0;
	}
	else if (D1 + D2 == 0) {
		cout << "infinity";
	}
	else {
		// D1 + D2 < 0
		// abs(D1) < abs(D2)
		D3 = -(D1 + D2);
		p = D1 / D3, q = D1 % D3;
		if (q) cout << p * 2 + 1;
		else cout << p * 2;
	}
	return 0;
}