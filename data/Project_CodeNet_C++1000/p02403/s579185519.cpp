#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
	int h, w, i, j;
	while (1) {
		cin >> h >> w;
		if (!h && !w)
			break;
		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
				cout << '#';
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}