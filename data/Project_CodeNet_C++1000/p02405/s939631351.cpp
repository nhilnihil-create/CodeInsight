#include<iostream>
#include<stdio.h>

using namespace std;

int main() {
	int H, W;
	int c = 1;
	int d = -1;

	while (1) {

		cin >> H >> W;

		if (H == 0 && W == 0) {
			return 0;
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {

				if (c == 1) {
					cout << '#';
					c = -1;
				}
				else {
					cout << '.';
					c = 1;
				}

			}
			cout << endl;

			c = d;
			d = d *(-1);
		}

		c = 1;
		d = -1;
		cout << endl;

	}
	return 0;
}