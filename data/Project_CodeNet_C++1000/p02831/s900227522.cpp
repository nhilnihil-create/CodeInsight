#include "bits/stdc++.h"

using namespace std;
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

long long lcm(long long x, long long y) {
	return x * y / gcd(x, y);
}

int main() {
	long long A,B;
	cin >> A >>B;
	cout << lcm(A,B)<<  endl;
	
	return 0;
}
