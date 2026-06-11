#include <iostream>

int main() {
	using namespace std;
	for (;;) {
		int n;
		cin >> n;
		if (cin.eof()) { break; }

		int pair = 0;
		for (int a = 0; a <= 9; ++a) {
			for (int b = 0; b <= 9; ++b) {
				int ab = a + b;
				for (int c = 0; c <= 9; ++c) {
					int abc = ab + c;
					for (int d = 0; d <= 9; ++d) {
						if (abc + d == n) { ++pair; }
					}
				}
			}
		}

		cout << pair << endl;
	}
	return 0;
}