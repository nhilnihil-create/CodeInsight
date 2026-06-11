#include "bits/stdc++.h"

using namespace std;

template<class T>
T gcd(T a, T b) {
	while (b != 0) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x;
	cin >> x;
	cout << 360 / gcd(x, 360) << '\n';
	return 0;
}