#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	long long res = a / gcd(a, b) * b;
	return res;
}

int main() {
	long long A, B;
	cin >> A >> B;
	long long ans = lcm(A, B);
	cout << ans << endl;
	return 0;
}