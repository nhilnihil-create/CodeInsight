#include <iostream>
using namespace std;

int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

int main() {
	int n; cin >> n;
	cout << n / gcd(360, n) * 360 / n;
	return 0;
}