#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x) {
	if (x % 2 == 0) {
		return x == 2;
	}
	for (int i = 3; i <= sqrt(x); i+=2) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (!is_prime(n)) ++n;
	cout << n << endl;
	return 0;
}