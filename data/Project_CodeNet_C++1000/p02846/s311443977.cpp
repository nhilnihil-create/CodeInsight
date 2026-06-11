#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int main() {
	ll T1, T2;
	ll A1, B1, A2, B2;
	cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;

	if (T1 * A1 + T2 * A2 == T1 * B1 + T2 * B2) {
		cout << "infinity" << endl;
		return 0;
	}

	if (T1 * (A1 - B1) + T2 * (A2 - B2) > 0) {
		if (A1 - B1 >= 0) {
			cout << 0 << endl;
			return 0;
		}
		ll Diff = T1 * (A1 - B1) + T2 * (A2 - B2);
		ll ans = (T2 * (A2 - B2)) / Diff;
		if (ans * Diff == (T2 * (A2 - B2)))cout << ans * 2 - 2 << endl;
		else cout << ans * 2 - 1 << endl;
	}

	if (T1 * (A1 - B1) + T2 * (A2 - B2) < 0) {
		if (A1 - B1 <= 0) {
			cout << 0 << endl;
			return 0;
		}
		ll Diff = -(T1 * (A1 - B1) + T2 * (A2 - B2));
		ll ans = (T1 * (A1 - B1)) / Diff;
		ans++;
		if((ans - 1) * Diff == (T1 * (A1 - B1)))cout << ans * 2 - 2 << endl;
		else cout << ans * 2 - 1 << endl;
	}

	return 0;
}
