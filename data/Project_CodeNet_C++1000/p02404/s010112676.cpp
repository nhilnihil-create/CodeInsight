#include <iostream>

using namespace std;

int main() {
	int H, W;
	while (1) {
		cin >> H >> W;
		if (H == 0 && W == 0)break;
		for (int i = 0; i < H; i++) {
			if (i != 0 && i != H - 1) {
				for (int j = 0; j < W; j++) {
					if (j == W - 1) {
						cout << "#" << endl;
					}
					else if(j == 0){
						cout << "#";
					}
					else {
						cout << ".";
					}
				}
			}
			else {
				for (int j = 0; j < W; j++) {
					if (j == W - 1) {
						cout << "#" << endl;
					}
					else {
						cout << "#";
					}
				}
			}
		}
		cout << "" << endl;
	}
}