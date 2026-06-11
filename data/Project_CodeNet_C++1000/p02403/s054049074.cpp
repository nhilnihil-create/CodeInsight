#include <iostream>
#include <ctime>
#define ESP 1e-10
using namespace std;
int main() {
	while (true) {
		int H, W; cin >> H >> W;
		if (H == 0 && W == 0) {
			for (int i = 0; i < 100000000; i++) { int j = i; }
			break;
		}
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W;j++) {
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}


}