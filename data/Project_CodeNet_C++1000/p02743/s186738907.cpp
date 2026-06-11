#include "bits/stdc++.h"
using namespace std;

int main() {
	long long int a, b, c;
	cin >> a >> b >> c;

	long long int d = c - a - b;

	if (d * d > 4 * a * b && d > 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}