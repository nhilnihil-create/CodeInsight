#include <iostream>
#include <string.h>

using namespace std;
int main() {
	int h=1, w=1;
	while (h != 0 && w != 0) {
		cin >> h;
		cin >> w;
		if (h == 0 && w == 0) continue;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << "#";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}