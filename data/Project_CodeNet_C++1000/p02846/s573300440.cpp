#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	Int T1, T2, A1, A2, B1, B2;
	cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

	Int Tx = T1 * A1 + T2 * A2;
	Int Ax = T1 * B1 + T2 * B2;

	if (Tx == Ax) {
		cout << "infinity" << endl;
		return 0;
	}

	Int Tx1 = T1 * A1;
	Int Ax1 = T1 * B1;
	if ((Tx1 < Ax1 && Tx < Ax) || (Tx1 > Ax1 && Tx > Ax)) {
		cerr << "fu" << endl;
		cout << 0 << endl;
		return 0;
	}

	if (Tx > Ax) {
		swap(Ax1, Tx1);
		swap(Ax, Tx);
	}
	Int x = (Tx1 - Ax1) / (Ax - Tx);
	Int ans = 2 * x;
	if ((Tx1 - Ax1) % (Ax - Tx) != 0) { ++ans; }
	
	cout << ans << endl;

	return 0;
}
