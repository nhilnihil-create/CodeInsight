#include <iostream>
using namespace std;
int main() {
	int n, a[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	cin >> n;
	int b[n];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (a[i][j] == b[k])
					a[i][j] = 1;
			}
		}
	}
	int ans = 0;
	if (a[0][0] == 1 && a[0][1] == 1 && a[0][2] == 1)
		ans++;
	if (a[1][0] == 1 && a[1][1] == 1 && a[1][2] == 1)
		ans++;
	if (a[2][0] == 1 && a[2][1] == 1 && a[2][2] == 1)
		ans++;
	if (a[0][0] == 1 && a[1][1] == 1 && a[2][2] == 1)
		ans++;
	if (a[0][0] == 1 && a[1][0] == 1 && a[2][0] == 1)
		ans++;
	if (a[0][1] == 1 && a[1][1] == 1 && a[2][1] == 1)
		ans++;
	if (a[0][2] == 1 && a[1][2] == 1 && a[2][2] == 1)
		ans++;
	if (a[0][2] == 1 && a[1][1] == 1 && a[2][0] == 1)
		ans++;
	if (ans >= 1)
		cout << "Yes" << "\n";
	else 
		cout << "No" << "\n";
}