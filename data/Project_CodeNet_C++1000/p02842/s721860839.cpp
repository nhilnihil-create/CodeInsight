#include <bits/stdc++.h>
using namespace std;

int main () {
	int x; cin >> x;
	for (int i = 1; i <= 50000; ++i) {
		if (int(double(i)*1.08) == x) {
			cout << i << endl;
			return 0;
		}
	}
	cout << ":(\n";
	return 0;
}