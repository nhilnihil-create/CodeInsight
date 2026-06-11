#include<iostream>
using namespace std;
int main() {
	int n, a,b,c,d, r[5][4][12] = { 0 };
	cin >> n;
	while (n--) {
		cin >> a >> b >> c >> d;
		r[a][b][c] += d;
	}
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 3; j++) {
			for (int k = 1; k <= 10; k++) {
				cout << ' ' << r[i][j][k];
			}
			cout << endl;
		}
		if (i == 4);
		else cout << "####################" << endl;
	}
	return 0;
}