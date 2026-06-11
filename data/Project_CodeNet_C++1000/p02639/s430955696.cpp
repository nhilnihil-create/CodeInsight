#include <iostream>

using namespace std;

int main() {
	int xs[5];
	for (auto &x : xs) {
		cin >> x;
	}
	for (int i = 1; i <= 5; ++i) {
		if (xs[i - 1] != i) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}