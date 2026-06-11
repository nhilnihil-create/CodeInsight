#include<iostream>
using namespace std;
int main() {

	//A
	int h, w, a, b;
	cin >> h;
	cin >> w;
	cin >> a;
	cin >> b;

	int i, j, k;
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if ((i < b) && (j < a)) {
				cout << 1;
			}
			else if ((i >= b) && (j >= a)) {
				cout << 1;
			}
			else {
				cout << 0;
			}
		}
		cout << '\n';
	}

	return 0;
}