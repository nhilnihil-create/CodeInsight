#include <iostream>

using namespace std;

int main() {
	int n;
	while (cin >> n&& n!=0) {
		int f[21][21] = {};

		for (int i = 0; i<n; i++) {
			int x, y;
			cin >> x >> y;
			f[y][x] = 1;
		}

		int x = 10, y = 10;
		int cnt = 0;

		int m;
		cin >> m;
		for (int i = 0; i<m; i++) {
			char dir;
			int step;
			cin >> dir >> step;
			while (step--) {
				if (dir == 'N') { y++; }
				else if (dir == 'S') { y--; }
				else if (dir == 'E') { x++; }
				else { x--; }

				if (f[y][x]) {
					f[y][x] = 0;
					cnt++;
				}
			}
		}

		if (cnt == n) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}

	return 0;
}
