#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int m, n;
	while (cin >> m >> n, m, n) {
		int t[100];
		int h[100];
		for (int i = 0;i < m;i++)cin >> t[i];
		for (int i = 0;i < n;i++)cin >> h[i];

		int st = 0, sh = 0;
		for (int i = 0;i < m;i++)st += t[i];
		for (int i = 0;i < n;i++)sh += h[i];

		int a = 1e8, b = 1e8;
		int flg = 1;

		for (int i = 0;i < m;i++) {
			for (int j = 0;j < n;j++) {
				if (st - t[i] + h[j] == sh - h[j] + t[i]) {
					if (t[i] + h[j] < a + b) {
						a = t[i];
						b = h[j];
						flg = 0;
					}
				}
			}
		}
		if (flg == 1)cout << -1 << endl;
		else cout << a << ' ' << b << endl;
		
	}
	return 0;
}