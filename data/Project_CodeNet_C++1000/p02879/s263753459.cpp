#include <iostream>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;

	int ans = -1;
	if (1 <= A && A <= 9 && 1 <= B && B <= 9) {
		ans = A * B;
	}
	cout << ans << endl;
	return 0;
}
