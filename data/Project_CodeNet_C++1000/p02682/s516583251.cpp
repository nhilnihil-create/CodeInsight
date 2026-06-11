#include <bits/stdc++.h>
#include <iostream>

#define ll long long

using namespace std;

int main() {
	ll a, b, c, k;
	cin >> a >> b >> c >> k;
	if (k <= a) {
		cout << k;
		return 0;
	}
	if (k <= a + b) {
		cout << a;
		return 0;
	}
	cout << 2*a+b-k;
}
