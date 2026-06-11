#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int l, r, d;
	cin >> l >> r >> d;
	if (l % d != 0) {
		l += (d - l % d);
	}
	r -= (r % d);
	cout << (r-l)/d+1;
}
