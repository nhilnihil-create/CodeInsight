#include <iostream>

using namespace std;

int main(void) {
	int ryou[4][3][10] = { 0 };

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int b, f, r, v;
		cin >> b >> f >> r >> v;

		ryou[b - 1][f - 1][r - 1] += v;

		if (ryou[b - 1][f - 1][r - 1] < 0) {
			ryou[b - 1][f - 1][r - 1] = 0;
		}
	}

	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 3; y++) {
			for (int z = 0; z < 10; z++) {
				cout << " " << ryou[x][y][z];
			}
			cout << endl;
		}
		if (x == 3) {
			break;
		}
		cout << "####################" << endl;
	}

	return 0;
}