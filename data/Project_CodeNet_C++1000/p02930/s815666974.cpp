#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int dis[555], used[555];

int d[555][555];

int check[555];

int INF = 9998;
void CALC(int K, int num) {
	
	used[K] = 1;

	for (int m = 1; m <= K-1; m++) {
		if (used[m] == 0 && d[K][m] == num) { dis[m] = dis[K] + 1; CALC(m, num); }
	}

}

int main(void) {

	cin >> N;

	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= i; j++) {check[j] = 0; }

		int Q = 1;
		for (int j = i-1; j >=1; j--) {
			if (check[j] != 0) { continue; }

			d[i][j] = Q; d[j][i] = Q;  check[j] = 1;

			for (int k = 1; k <= i - 1; k++) { dis[k] = INF; used[k] = 0; }
			dis[i] = 0;
			CALC(i, Q);

			for (int k = 1; k <= j; k++) {
				if (dis[k] % 2 == 1) { check[k] = 1; d[i][k] = Q; d[k][i] = Q; }
			}

			Q++;
		}

	}

	for (int i = 1; i <= N - 1; i++) {
		for (int j = i+1; j <= N; j++) {
			if (j != i+1) { cout << " "; }
			cout << d[i][j];
		}cout << endl;
	}

	return 0;
}