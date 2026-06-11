#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using VI = vector<int>;
using PI = pair<int, int>;

int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

int main() {
	int x, y;
	cin >> x >> y;
	cout << gcd(x, y) << endl;
	return 0;
}

