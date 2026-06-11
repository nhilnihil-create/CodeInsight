#include <iostream>
using namespace std;

int dx[] = { 0,  1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1,  1,  0, -1};

int map[51][51];
int w, h;

void oneIsland(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if ((0 <= nextX && nextX < w)
			&& (0 <= nextY && nextY < h)) {
			if (map[nextY][nextX] == 1) {
				map[nextY][nextX] = 0;
				oneIsland(nextX, nextY);
			}
		}
	}
}

int main() {
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		
		int count = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) {
					map[i][j] = 0;
					count++;
					oneIsland(j, i);
				}
			}
		}
		cout << count <<endl;
	}
	return 0;
}