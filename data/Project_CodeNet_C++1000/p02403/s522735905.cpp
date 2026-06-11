#include <iostream>

using namespace std;

int main() {

	int endOfInput;
	int h[1000], w[1000];

	for (int i = 0;; i++) {

		cin >> h[i] >> w[i];

		if (h[i] == 0 && w[i] == 0) {
			endOfInput = i;
			break;
		}

	}

	for (int i = 0; i < endOfInput; i++) {
		for (int j = 0; j < h[i]; j++) {
			for (int k = 0; k < w[i]; k++) {
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;

}