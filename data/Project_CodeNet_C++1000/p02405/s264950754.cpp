#include<iostream>
using namespace std;

int main() {
	int H, W;
	while (1) {
		cin >> H >> W;
		if (H == 0 && W == 0)break;
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				if (h % 2 == 0 && w % 2 == 0)cout << "#";
				if (h % 2 == 0 && w % 2 != 0)cout << ".";
				if (h % 2 != 0 && w % 2 == 0)cout << ".";
				if (h % 2 != 0 && w % 2 != 0)cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}