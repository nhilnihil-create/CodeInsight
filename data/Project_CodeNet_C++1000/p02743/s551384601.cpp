#include <iostream>
using namespace std;

bool check(long a, long b, long c) {
	if (c - a - b < 0) {
		return false;
	}
	return (c - a - b) * (c - a - b) > 4 * a * b;
}

int main() {
	long a, b, c;
	cin >> a >> b >> c;

	cout << (check(a, b, c) ? "Yes" : "No") << endl;

	return 0;
}