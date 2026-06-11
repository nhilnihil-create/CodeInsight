#include "bits/stdc++.h"
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

void solve(mat &M, int H, int W) {
	int NOW = 0;
	for (int i = 0; i < W; i++) {
		bool check = false;
		for (int j = NOW; j < H; j++) {
			if (M[j][i] != 0) {
				swap(M[j], M[NOW]);
				check = true;
				break;
			}
		}
		if (!check) continue;
		for (int j = 0; j < H; j++) {
			if (j != NOW && M[j][i] != 0) {
				for (int k = 0; k < W; k++) {
					M[j][k] = M[j][k] ^ M[NOW][k];
				}
			}
		}
		NOW++;
	}
}

int main() {
	long long N, XOR = 0, ANS = 0;
	static long long A[100000], V[60] = {};
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i], XOR = XOR ^ A[i];
	mat M(N, vec(60));
	ANS = XOR;
	for (int i = 1; i <= 60; i++) {
		V[60 - i] = XOR % 2;
		XOR /= 2;
	}
	for (int i = 0; i < N; i++) {
		long long X = A[i];
		for (int j = 1; j <= 60; j++) {
			if (V[60 - j] == 0) M[i][60 - j] = X % 2;
			else M[i][60 - j] = 0;
			X /= 2;
		}
	}
	solve(M, N, 60);
	long long Cur = 2;
	for (int i = 59; i >= 0; i--) {
		long long COUNT = 0;
		for (int j = 0; j < N; j++) {
			COUNT += M[j][i];
		}
		ANS += Cur * (COUNT % 2);
		Cur *= 2;
	}
	cout << ANS << endl;
}