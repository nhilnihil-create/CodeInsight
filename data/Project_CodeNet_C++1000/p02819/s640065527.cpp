#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main() {
	int x;
	cin >> x;
	while (!is_prime(x)) {
		x++;
	}
	cout << x << '\n';
	return 0;
}
