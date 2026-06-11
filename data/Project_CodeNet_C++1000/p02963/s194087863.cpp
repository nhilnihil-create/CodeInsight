#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long S;
	cin >> S;
	const long long L = pow(10, 9);
	long long x, y;
	if (S < L * L) {
		y = S / L + 1;
		x = L * y - S;
	}
	else {
		y = L;
		x = 0;
	}
	cout << "0 0 " << L << " 1 " << x << " " << y << endl;
}