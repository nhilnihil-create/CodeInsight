#include <iostream>
using namespace std;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	int a, b; cin >> a >> b;
	int min8 = (a * 100 + 7) / 8;
	int max8 = ((a + 1) * 100 + 7) / 8 - 1;
	int min10 = (b * 100 + 9) / 10;
	int max10 = ((b + 1) * 100 + 9) / 10 - 1;

	if (min8 < min10) {
		if (max8 < min10) cout << -1;
		else cout << min10;
	}
	else {
		if (max10 < min8) cout << -1;
		else cout << min8;
	}
	return 0;
}