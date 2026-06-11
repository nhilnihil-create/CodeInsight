#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

char swapc(char c) {
	if (c == '#')
		return '.';
	else if (c == '.')
		return '#';
	else
		return ' ';
}

int main() {
	int H, W;
	while (cin >> H >> W && (H || W)) {
		for (int i = 0; i < H; i++) {
			char c;
			if (i % 2 == 0)
				c = '#';
			else
				c = '.';
			for (int j = 0; j < W; j++) {
				cout << c;
				c = swapc(c);
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}