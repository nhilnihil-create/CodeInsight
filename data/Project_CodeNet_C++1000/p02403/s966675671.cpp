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
			for (i = 1; i <= W; i++) {
				if (i != W) {
					cout << "#";
				} else {
					cout << "#" << endl;
				}
			}
			if(k == H){
				cout << "\n";
			}
		}
	}
	return 0;
}