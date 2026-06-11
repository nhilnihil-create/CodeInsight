#include <iostream>
using namespace std;
int main(void) {
	int a[200][200], b[200][200];
	long long int c[200][200] = {};
	int n, m, l;
	cin >> n >> m >> l;
	for (int d = 1; d <= n; d++) {
		for (int e = 1; e <= m; e++) {
			cin >> a[d][e];
		}
	}
	for (int d = 1; d <= m; d++) {
		for (int e = 1; e <= l; e++) {
			cin >> b[d][e];
		}
	}
	for (int d = 1; d <= n; d++) {
		for (int e = 1; e <= l; e++) {
			for (int f = 1; f <= m; f++) {
				c[d][e] += a[d][f] * b[f][e];
			}
		}
	}
	for (int d = 1; d <= n; d++) {
		for (int e = 1; e < l; e++) {
			cout << c[d][e] << " ";
		}
		cout << c[d][l] << endl;
	}
	return 0;
}