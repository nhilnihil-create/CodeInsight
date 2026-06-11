#include <iostream>

using namespace std;

int main() {
	int a, b, c, d;
	int max = 0;
	for (int i = 0; i < 2; ++i) {
		cin >> a >> b >> c >> d;
		int sum = a + b + c + d;
		if (sum > max) max = sum;
	}
	cout << max << endl;
	return 0;
}