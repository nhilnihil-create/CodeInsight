
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#define pi 3.14159265358979323846264338
using namespace std;

int main() {
	int h ,w;
	while (cin >> h >> w) {
		if (h == 0 && w == 0) {
			break;
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (i % 2 == 0) {
					if (j % 2 == 0) {
						cout << "#";
					}
					else {
						cout << ".";
					}
				}
				else {
					if (j % 2 == 0) {
						cout << ".";
					}
					else {
						cout << "#";
					}
				}
				if (j == w - 1) {
					cout << endl;
				}
			}
		}
		cout << endl;
	}
	return 0;
}