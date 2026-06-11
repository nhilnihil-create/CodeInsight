#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const long long mod = 1e9 + 7;

ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	int m1, d1, m2, d2;
	cin >> m1 >> d1 >> m2 >> d2;

	if (m1 != m2)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}
}