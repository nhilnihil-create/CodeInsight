#include <iostream>
using namespace std;
long long gcd(long long x, long long y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}
long long calc(long long A, long long X, long long Y) {
	return A - A / X - A / Y + A / (X / gcd(X, Y) * Y);
}
int main() {
	long long A, B, C, D;
	cin >> A >> B >> C >> D;
	cout << calc(B, C, D) - calc(A - 1, C, D) << endl;
	return 0;
}