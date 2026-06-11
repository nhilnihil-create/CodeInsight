#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int h, sum;
vvi board;

void drop(int i, int j) {
	if (i == h - 1) return;
	if (board[i][j] > 0 && board[i + 1][j] == 0) {
		swap(board[i][j], board[i + 1][j]);
		drop(i + 1, j);
	}
}

int chain(int i, int j) {
	if (j == 4) return 1;
	if (board[i][j] != board[i][j + 1]) return 1;
	return 1 + chain(i, j + 1);
}

void calc() {
	int presum = sum;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < 5;) {
			int c = chain(i, j);
			if (c >= 3) {
				sum += board[i][j] * c;
				for (int k = 0; k < c; k++) {
					board[i][j + k] = 0;
				}
			}
			j += c;
		}
	}

	for (int i = h - 1; i >=0; i--) {
		for (int j = 0; j < 5; j++) {
			drop(i, j);
		}
	}
	if (presum != sum)
		calc();
}

int main() {
	while (cin >> h , h != 0) {
		board = vvi(h, vi(5, 0));
		sum = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> board[i][j];
			}
		}
		calc();
		cout << sum << endl;
	}

}