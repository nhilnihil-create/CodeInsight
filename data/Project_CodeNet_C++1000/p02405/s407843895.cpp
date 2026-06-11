#include <iostream>

using namespace std;

int main() {
	int H, W;
	while (1) {
		cin >> H >> W;
		if (H == 0 && W == 0)break;
		for (int i = 0; i < H; i++) {
			if (i % 2 == 0) {
				for (int j = 0; j < W; j++) {
					if (j == W - 1) {
						if (j % 2 == 0) {
							cout << "#" << endl;
						}
						else {
							cout << "." << endl;
						}
						
					}
					else if(j % 2 == 0){
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
						if (j % 2 == 0) {
							cout << "." << endl;
						}
						else {
							cout << "#" << endl;
						}
						
					}
					else if(j % 2 == 0){
						cout << ".";
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