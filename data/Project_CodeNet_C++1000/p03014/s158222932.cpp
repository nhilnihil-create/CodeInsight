#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int H, W;
vector<string> S;
vector<vi> U, D, L, R;

void input_init(void) {
	cin >> H >> W;
	S.resize(H);
	for (int i = 0; i < H; ++i)
		cin >> S[i];
	U.resize(H, vi(W, 0));
	D.resize(H, vi(W, 0));
	L.resize(H, vi(W, 0));
	R.resize(H, vi(W, 0));
}

void pre_calcu(void) {
	for (int i = 0; i < W; ++i)
		U[0][i] = (S[0][i] == '.') ? 1 : 0;
	for (int j = 1; j < H; ++j) {
		for (int i = 0; i < W; ++i)
			U[j][i] = (S[j][i] == '.') ? U[j - 1][i] + 1 : 0;
	}
	for (int i = 0; i < W; ++i)
		D[H - 1][i] = (S[H - 1][i] == '.') ? 1 : 0;
	for (int j = H - 2; j >= 0; --j) {
		for (int i = 0; i < W; ++i)
			D[j][i] = (S[j][i] == '.') ? D[j + 1][i] + 1 : 0;
	}
	for (int j = 0; j < H; ++j)
		L[j][0] = (S[j][0] == '.') ? 1 : 0;
	for (int i = 1; i < W; ++i) {
		for (int j = 0; j < H; ++j)
			L[j][i] = (S[j][i] == '.') ? L[j][i - 1] + 1 : 0;
	}
	for (int j = 0; j < H; ++j)
		R[j][W - 1] = (S[j][W - 1] == '.') ? 1 : 0;
	for (int i = W - 2; i >= 0; --i) {
		for (int j = 0; j < H; ++j)
			R[j][i] = (S[j][i] == '.') ? R[j][i + 1] + 1 : 0;
	}
}

int solve(void) {
	int max_cnt = 0;
	for (int j = 0; j < H; ++j) {
		for (int i = 0; i < W; ++i) {
			if (S[j][i] == '#')
				continue;
			int cnt = 1;
			if (j - 1 >= 0)
				cnt += U[j - 1][i];
			if (j + 1 < H)
				cnt += D[j + 1][i];
			if (i - 1 >= 0)
				cnt += L[j][i - 1];
			if (i + 1 < W)
				cnt += R[j][i + 1];
			max_cnt = max(cnt, max_cnt);
		}
	}

	return max_cnt;
}

int main(void) {
	input_init();
	pre_calcu();
	int ans = solve();
	cout << ans << '\n';
	return 0;
}
