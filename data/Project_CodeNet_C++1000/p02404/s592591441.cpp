#include <iostream>
using namespace std;

int main() {
	int H, W;

	do {
		cin >> H >> W;
		if(H == 0 && W == 0) break;

		for(int h = 0; h < H; ++h) {
			if(h == 0 || h == H - 1) {
				for(int w = 0; w < W; ++w) {
					cout << "#";
				}
				cout << endl;
			} else {
				for(int w = 0; w < W; ++w) {
					if(w == 0 || w == W - 1) {
						cout << "#";
					} else {
						cout << ".";
					}
				}
				cout << endl;
			}
		}
		cout << endl;
	} while(true);
	
	return 0;
}