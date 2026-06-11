#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	Int T1, T2, A1, A2, B1, B2;
	cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

	Int P = T1 * (A1 - B1);
	Int Q = T2 * (A2 - B2);

	if (P > 0) {
		P *= -1;
		Q *= -1;
	}

	if (P + Q == 0) {
		cout << "infinity" << endl;
		return 0;
	}
	if (P + Q < 0) { 
		cout << 0 << endl;
		return 0;
	}

	Int ans = -P / (P + Q) * 2;
	if (-P % (P + Q) != 0) { ++ans; }
	cout << ans << endl;

	return 0;
}
