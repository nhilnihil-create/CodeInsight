#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>

using namespace std;


int main(void) {

	int H, W;

	while (cin >> H >> W, H, W) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (i % 2 == 0 && j % 2 == 0)
					cout << "#";
				else if (i % 2 != 0 && j % 2 != 0)
					cout << "#";
				else
					cout << ".";
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}