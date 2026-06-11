#include<iostream>

using namespace std;

int main() {
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {

		int x = i;

		if (x % 3 == 0) {
			cout << " " << i;
		}

		else if (x % 10 == 3) {
			cout << " " << i;
		}

		else {
			for (int j = 0; j < x; j++) {
				x /= 10;
				if (x % 10 == 3) {
					cout << " " << i;
					break;
				}
			}
		}
	}
	cout << endl;

	return 0;
}
