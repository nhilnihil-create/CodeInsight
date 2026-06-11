#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int X;
	cin >> X;
	int prime;
	while (true) {
		bool ok = true;
		int root_X = sqrt(X);
		for (int i = 2; i <= root_X; i++) {
			if (X % i == 0) {
				ok = false;
			}
		}
		if (ok) {
			prime = X;
			break;
		}
		X++;
	}
	cout << prime << endl;
	return 0;
}