#include "bits/stdc++.h"
using namespace std;

long  long gcd(long long a, long long b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

long long  lcm(long long x, long long y) {
	return x * y / gcd(x, y);
}

int main() {
	long long A,B,C,D;
	cin >> A>>B>>C>>D;
	A--;
	long long ans1 = A / C + A / D - A / (lcm(C, D));
	long long ans2 = B / C + B / D - B / (lcm(C, D));
	cout << (B-A)-(ans2 -ans1)<<endl;
	return 0;
}
