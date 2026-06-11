#include <iostream>

using namespace std;
using ll = long long;

int main() {
	int A, B;
	cin >> A >> B;

	int mul = min(A, B);
	int div = max(A, B);
	ll ans = mul;
	while (true) {
		ans += mul;
		if (ans % div == 0) {
			cout << ans << endl;
			return 0;
		}
	}
	return 0;
}
