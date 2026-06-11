#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << (LL) a * b / gcd(a, b) << '\n';
	return 0;
}
