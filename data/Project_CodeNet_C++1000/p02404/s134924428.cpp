#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int H, W;

	while (1) {
		cin >> H >> W;
		if (H == 0 && W == 0) break;

		for (int i = 0; i < H; i++) {
			if (0 < i && i < H-1) {
				for (int j = 0; j < W; j++) {
					if (0 < j && j < W-1) {
						cout << "." ;
					}
					else  {
						cout << "#";
					}
				}
			}else if (i == 0 || i == H-1) {
				for (int j = 0; j < W; j++) {
					cout << "#";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}