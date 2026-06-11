#include <iostream>
using namespace std;

int main() {
	int H, W;

	do {
		cin >> H >> W;
		if(H == 0 && W == 0) break;

		for(int h = 0; h < H; ++h) {
			for(int w = 0; w < W; ++w) {
				if((w + h) % 2 == 0) {
					cout << "#";
				} else {
					cout << ".";
				}
			}
			cout << endl;
		}
		cout << endl;
	} while(true);
	
	return 0;
}