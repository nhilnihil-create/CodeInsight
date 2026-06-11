//#include "stdafx.h"
#include <iostream>

using namespace std;

char map[101][101];
int direction[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int row, col;
char now;

void DFS(int x, int y) {
	map[x][y] = '.';
	
	int nextX, nextY;
	
	for (int i = 0; i < 4; i++) {
		nextX = x + direction[i][0];
		nextY = y + direction[i][1];

		if (nextX >= 0 && nextY >= 0 && nextX < row && nextY < col && map[nextX][nextY] == now) {
			DFS(nextX, nextY);
		}
	}
}

int main() {
	int sum;
	while (cin >> row >> col) {
		if (row == 0 && col == 0)break;
		for (int i = 0; i < row; i++)
			cin >> map[i];

		sum = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] != '.') {
					now = map[i][j];
					sum++;
					DFS(i, j);
				}
			}
		}
		cout << sum << endl;
	}

}
