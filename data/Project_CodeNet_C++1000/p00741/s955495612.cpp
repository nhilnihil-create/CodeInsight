#include <iostream>

using namespace std;

const int MAX_SIZE = 51;

int field[MAX_SIZE][MAX_SIZE];
int w, h;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1},
	dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool ok(int y, int x) {
	return x >= 0 && x < w && y >= 0 && y < h;
}

void consume(int y, int x) {
	bool flag = false;
	for (int i = 0; i < 8; ++i) {
		int curx = x + dx[i],
			cury = y + dy[i];
		if (ok(cury, curx) && field[cury][curx] == 1) {
			field[cury][curx] = 0;
			consume(cury, curx);
		}
	}
}

int main() {
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j)
			cin >> field[i][j];

		int res = 0;
		for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
			if (field[i][j] == 1) {
				field[i][j] = 0;
				consume(i, j);
				++res;
			}
		}
		
		cout << res << endl;
	}
	return 0;
}