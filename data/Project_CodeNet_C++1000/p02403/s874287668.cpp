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
				cout << '#';
			}
			cout << endl;
		}
		cout << endl;
	}
}