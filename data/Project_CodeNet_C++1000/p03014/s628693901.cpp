#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int H, W;
	cin >> H >> W;

	vector<string> v(H);
	for (int i = 0; i < H; i++) cin >> v[i];

	vector<vector<int>> L(H, vector<int>(W)), R(H, vector<int>(W)),
		U(H, vector<int>(W)), D(H, vector<int>(W));

	for (int i = 0; i < H; i++) {
		int c = 0;
		for (int j = 0; j < W; j++) {
			char ch = v[i][j];
			if (ch == '#') c = 0;
			else c++;
			L[i][j] = c;
		}
	}

	for (int i = 0; i < H; i++) {
		int c = 0;
		for (int j = W - 1; j >= 0; j--) {
			char ch = v[i][j];
			if (ch == '#') c = 0;
			else c++;
			R[i][j] = c;
		}
	}

	for (int i = 0; i < W; i++) {
		int c = 0;
		for (int j = 0; j < H; j++) {
			char ch = v[j][i];
			if (ch == '#') c = 0;
			else c++;
			U[j][i] = c;
		}
	}

	for (int i = 0; i < W; i++) {
		int c = 0;
		for (int j = H - 1; j >= 0; j--) {
			char ch = v[j][i];
			if (ch == '#') c = 0;
			else c++;
			D[j][i] = c;
		}
	}

	int ret = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			int n = L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3;
			ret = max(ret, n);
		}
	}

	cout << ret << endl;
}