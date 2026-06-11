#include <iostream>
#include <ctime>
#define ESP 1e-10
using namespace std;
int main() {
	bool flag = false;
	time_t c1;
	while (true) {
		int H, W; cin >> H >> W;
		if (!flag) { c1 = clock(); flag = true; }
		if (H == 0 && W == 0) break;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W;j++) {
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}
	time_t c2;
	while (true) {
		c2 = clock();
		if (c2 - c1 > 999) break;
	}
}