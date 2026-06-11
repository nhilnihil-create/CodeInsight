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
			if (k == 1 || k == H) {

				for (i = 1; i <= W; i++) {
					if (i != W) {
						cout << "#";
					} else {
						cout << "#" << endl;
					}
				}
			} else {
				for (i = 1; i <= W; i++) {
					if (i == 1) {
						cout << "#";
					} else if (i != W) {
						cout << ".";
					} else {
						cout << "#" << endl;
					}
				}
			}
		}
		cout << endl;
	}
	return 0;
}