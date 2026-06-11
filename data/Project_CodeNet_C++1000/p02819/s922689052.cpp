#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;
	cin >> x;
	for (int i = x; 1; i++) {
		bool f = true;
		for (int j = 2; j*j <= i; j++) {
			if (i%j==0) {
				f = false;
				break;
			}
		}
		if (f) {
			cout << i << endl;
			return 0;
		}
	}
}