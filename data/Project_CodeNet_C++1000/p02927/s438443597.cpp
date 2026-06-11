#include <iostream>
using namespace std;

int main() {
	int M, D;
	cin >> M >> D;
	int cnt = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 22; j <= D; j++) {
			int d1, d10;
			d1 = (j % 10);
			d10 = ((j / 10) % 10);
			if (d1 < 2 || d10 < 2) continue;
			if (d1 * d10 == i) cnt++;
		}
	}

	cout << cnt << endl;
}