#include <iostream>
using namespace std;
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int n, x, cnt;
	while (true) {
		cin >> n >> x;
		if (n == 0 && x == 0) break;
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				for (int k = j + 1; k <= n; k++) {
					if (i + j + k == x) cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
}