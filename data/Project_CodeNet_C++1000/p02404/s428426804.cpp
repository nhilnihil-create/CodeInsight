#include<iostream>
using namespace std;
int main() {
	int h, w;
	while (1) {
		cin >> h >> w;
		if (h == 0 && w == 0)
			break;
		for (int i = 0; i < h; i++) {
			for (int k = 0; k < w; k++) {
				if (i == 0 || i == h - 1 || k == 0 || k == w - 1) {
					cout << '#';
				}
				else cout << '.';
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}