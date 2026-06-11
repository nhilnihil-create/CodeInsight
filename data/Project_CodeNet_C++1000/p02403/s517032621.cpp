#include<iostream>
using namespace std;

int main() {
	int h, w;
	while (cin >> h >> w && h != 0 || w != 0) {
		for (int i = 0; i < h; ++i) {
			for (int i2 = 0; i2 < w; ++i2) {
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}