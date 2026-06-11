#include <iostream>
using namespace std;

int main() {
	int a, b, c ,d, ans_a, ans_b;
	cin >> a >> b >> c >> d;
	ans_a = (c / b) + ((c % b == 0) ? 0 : 1);
	ans_b = (a / d) + ((a % d == 0) ? 0 : 1);
	// cout << ans_a << " " << ans_b << "\n";
	if (ans_a <= ans_b) {
		cout << "Yes" << "\n";
	} else {
		cout << "No" << "\n";
	}
	return 0;
}
