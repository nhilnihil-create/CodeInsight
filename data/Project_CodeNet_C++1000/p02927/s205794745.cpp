#include <bits/stdc++.h>
using namespace std;
int m, d;
int main() {
	cin >> m >> d;
	int cnt = 0;
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= d; j ++) {
			int x = j % 10;
			int y = j / 10;
			if (x * y == i && x >= 2 && y >= 2) cnt++;
		}
	}
	cout << cnt << endl;
}