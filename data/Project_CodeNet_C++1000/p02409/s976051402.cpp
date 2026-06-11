#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
	int notice;
	int rooms[4][3][10];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 10; k++)
				rooms[i][j][k] = 0;

	cin >> notice;
	for (int i = 0; i < notice; i++) {
		int b, f, r, v;
		cin >> b >> f >> r >> v;
		rooms[b - 1][f - 1][r -1] += v;
		if (rooms[b - 1][f - 1][r -1] < 0) {
			rooms[b - 1][f - 1][r -1] = 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 10; k++)
				cout << " " << rooms[i][j][k];
			cout << endl;
		}
		if (i != 3) {
			for (int l = 0; l < 20; l++) cout << "#";
			cout << endl;
		}
	}
	return 0;
}

