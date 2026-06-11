#include "bits/stdc++.h"

using namespace std;
int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	long long d = c - a - b;
	if (((4 * a*b) < (d*d)) && (d > 0)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
