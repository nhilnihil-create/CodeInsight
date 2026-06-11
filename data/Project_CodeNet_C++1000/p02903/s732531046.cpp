#include <iostream>
#include <vector>
using namespace std;

int main() {
	int H, W, A, B;
	cin >> H >> W >> A >> B;
	vector<vector<bool>> ans(H, vector<bool>(W));
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B; j++) ans[j][i] = true;
	}
	for (int i = A; i < W; i++) {
		for (int j = B; j < H; j++) ans[j][i] = true;
	}
	for (vector<bool>& i : ans) {
		for (bool j : i) cout << j;
		cout << endl;
	}
}