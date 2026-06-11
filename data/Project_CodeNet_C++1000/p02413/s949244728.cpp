# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
using namespace std;

int main() {
	int r, c;
	cin >> r >> c;
	int map[150][150];
	for (int i = 1; i < 105; i++) {
		for (int j = 1; j < 105; j++) {
			map[i][j] = 0;
		}
	}
	int a;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> a;
			map[i][j] = a;
		}
	}
	for (int i = 1; i <= r; i++) {
		int sum = 0;
		for (int j = 1; j <= c; j++) {
			sum += map[i][j];
		}
		map[i][c + 1] = sum;
	}
	for (int j = 1; j <= c; j++) {
		int sum = 0;
		for (int i = 1; i <= r; i++) {
			sum += map[i][j];
		}
		map[r + 1][j] = sum;
	}
	for (int i = 1; i <= c; i++) {
		map[r + 1][c + 1] += map[r + 1][i];
	}
	for (int i = 1; i <= r + 1; i++) {
		for (int j = 1; j <= c + 1; j++) {
			if (j == c + 1) {
				cout << map[i][j] << endl;
			}
			else {
				cout << map[i][j] << " ";
			}
		}
	}
}