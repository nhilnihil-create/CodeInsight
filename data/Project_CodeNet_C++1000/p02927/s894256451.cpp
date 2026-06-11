#include <iostream>
using namespace std;

int main() {
	int M, D, ans = 0;
	cin >> M >> D;
	for (int i = 1; i <= M; ++i) {
		for (int j = 10; j <= D; ++j) {
			int d1 = j % 10, d10 = j / 10 % 10;
			if (2 <= d1 && 2 <= d10 && d1 * d10 == i) ++ans;
		}
	}
	cout << ans;
}