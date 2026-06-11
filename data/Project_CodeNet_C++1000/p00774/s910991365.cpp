#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

int main() {
	int a[10][5];
	int b;
	while (cin >> b, b) {
		for (int c = 0; c < b; c++) {
			for (int d = 0; d < 5; d++) {
				scanf("%d", &a[c][d]);
			}
		}
		bool S;
		int sum = 0;
		do {
			S = false;
			bool k[10][5]{};
			for (int c = 0; c < b; c++) {
				for (int d = 0; d <= 2; d++) {
					if (a[c][d] == a[c][d + 1]&&a[c][d] == a[c][d + 2] && a[c][d] != 0) {
						k[c][d] = k[c][d + 1] = k[c][d + 2] = true;
						S = true;
					}
				}
			}
			for (int c = 0; c < 5; c++) {
				for (int d = 0; d < b; d++) {
					if (k[d][c]) {
						sum += a[d][c];
						for (int e = d; e > 0; e--) {
							a[e][c] = a[e - 1][c];
						}
						a[0][c] = 0;
					}
				}
			}
		} while (S);
		cout << sum << endl;
	}
}