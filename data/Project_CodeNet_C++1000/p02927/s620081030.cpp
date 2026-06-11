#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int M, D;
	cin >> M >> D;
	if (D < 22) {
		cout << 0 << endl;
	}
	else {
		int ans = 0;
		for (int i = 22; i <= D; i++) {
			int d1 = i / 10;
			int d2 = i % 10;
			if (d2 < 2) continue;
			if (d1 * d2 <= M) ans++;
		}
		cout << ans << endl;
	}
}
