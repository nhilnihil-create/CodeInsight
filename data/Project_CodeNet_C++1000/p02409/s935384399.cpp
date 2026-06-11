#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int b, f, r, v, p = 0;
	int room[4][3][10] = { {} };
	for (int i = 0; i < n; i++) {
		cin >> b >> f >> r >> v;
		while (b < 1 && b > 4 && f < 1 && f > 3 && r < 1 && r > 10) {
			cin >> b >> f >> r >> v;
		}
		room[b - 1][f - 1][r - 1] = room[b - 1][f - 1][r - 1] + v;
		if (room[b - 1][f - 1][r - 1] > 9) {
			room[b - 1][f - 1][r - 1] = 9;
		}
		else if (room[b - 1][f - 1][r - 1] < 0) {
			room[b - 1][f - 1][r - 1] = 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 10; k++) {
				cout << " " << room[i][j][k];
			}
			cout << endl;
		}
		if (i < 3)
			cout << "####################" << endl;
	}
}
