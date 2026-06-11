#include<iostream>
using namespace std;

void write(int);

int main() {
	int H, W, x;

	while (true) {
		cin >> H >> W;
		if (H == 0 && W == 0)	break;

		for (int i = 0; i < H; i++) {
			x = i % 2;

			for (int j = 0; j < W; j++) {
				write(x);
				x++;
			}

			cout << endl;
		}

		cout << endl;
	}

	return 0;
}

void write(int x) {
	if (x % 2 == 0)	cout << '#';
	else cout << '.';
}