#include <iostream>
using namespace std;

int main() {
	int H, W, i, k;
	while (1) {
		cin >> H >> W;
		if (H == 0 && W == 0) {
			break;
		}

		for (k = 1; k <= H; k++) {
			if (k % 2 == 1) {
				for (i = 1; i <= W; i++) {
					if (i % 2 == 1) {
						cout << "#";
					} else {
						cout << ".";
					}
					if (i == W) {
						cout << endl;
					}
				}
			}else{
				for (i = 1; i <= W; i++) {
					if (i % 2 == 0) {
						cout << "#";
					} else {
						cout << ".";
					}
					if (i == W) {
						cout << endl;
					}
				}
			}
		}
		cout << endl;
	}

	return 0;
}