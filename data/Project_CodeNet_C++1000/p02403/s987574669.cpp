#include <iostream>

using namespace std;

int main() {

	int x, y;

	while (true) {

		cin >> x >> y;

		if (!(x | y))
			return 0;

		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				cout << '#';
			}
			cout << endl;
		}
		cout << endl;

	}

	return 0;

}