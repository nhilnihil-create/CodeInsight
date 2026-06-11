#include <iostream>

using namespace std;

int main() {
	int n;
	int count = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int num = i, digit = 0;
		while (num != 0) {
			num /= 10;
			digit++;
		}
		if (digit % 2 == 1) count++;
	}
	
	cout << count << endl;

	return 0;
}
