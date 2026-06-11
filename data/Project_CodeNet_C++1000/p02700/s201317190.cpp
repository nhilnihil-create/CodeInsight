#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b, p, q;
	cin >> a >> b >> p >> q;
	int i = 0;
	while (a > 0 && p > 0) {
		if (i & 1) {
			a = a - q;
		} else {
			p = p - b;
		}
		i++;
	}

	if (a <= 0) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
}