// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

long long count(long long n) {
	return n < 5 ? 0 : count(n / 5) + n / 5;
}

int main() {
	long long n; cin >> n;
	cout << (n % 2 == 0 ? count(n / 2) : 0) << '\n';
	return 0;
}
