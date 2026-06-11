#include<iostream>
using namespace std;

int main() {
	int a[101][101], b[101], c, i, j, n, m;
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (i = 1; i <= m; i++) {
		cin >> b[i];
	}
	for (i = 1; i <= n; i++) {
		c = 0;
		for (j = 1; j <= m; j++) {
			c += a[i][j] * b[j];
		}
		cout << c << endl;
	}
	return 0;
}