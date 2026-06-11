#include <iostream>
using namespace std;

int main() {
	int A[5][4][11], n;
	
	//三次元配列初期化
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 3; j++) {
			for (int k = 1; k <= 10; k++) {
				A[i][j][k] = 0;
			}
		}
	}

	//部屋にいる人数を入力
	cin >> n;
	for (int i = 0; i < n; i++) {
		int b, f, r, v;
		cin >> b >> f >> r >> v;
		A[b][f][r] += v;
	}
	
	for (int b = 1; b <= 4; b++) {
		if ( b > 1) cout << "####################" << endl;
		for (int f = 1; f <= 3; f++) {
			for (int r = 1; r <= 10; r++) {
				cout << " " << A[b][f][r];
			}
		cout << endl;
		}
	}

	return 0;
}
