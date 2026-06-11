#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <math.h>

using namespace std;

typedef long long ll;

int main() {
	int w, h;
	while ( cin >> h >> w, h || w ) {
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (x == 0 || y == 0 || x == w-1 || y == h-1) {
					cout << '#';
				}
				else {
					cout << '.';
				}
			}
			cout << endl;
		}
		cout << endl;
	}
}