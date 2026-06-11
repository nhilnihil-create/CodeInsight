#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[10][10] = {{}};
	int d = 1;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000) d *= 10;
		int x = i / d, y = i % 10;
		if (x == y) ans++;
		ans += a[y][x]*2;
		a[x][y]++;
	}
	cout << ans << endl;
	return 0;
}