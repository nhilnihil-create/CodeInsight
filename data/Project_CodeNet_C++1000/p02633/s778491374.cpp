#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

template <typename T>
T gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }

int main() {
	int X;
	cin >> X;
	cout << 360 / gcd(X, 360) << "\n";

	return 0;
}
