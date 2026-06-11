#include "bits/stdc++.h"
using namespace std;

int main() {
	string i, o;
	int ans = 0;
	cin >> i >> o;

	for (int n = 0; n < 3; n++) {
		if (i.at(n) == o.at(n)) {
			ans += 1;
		}
	}
	cout <<ans;
}
