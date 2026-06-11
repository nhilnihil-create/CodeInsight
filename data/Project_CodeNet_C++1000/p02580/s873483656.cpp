#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <assert.h>
#include <sstream>
typedef long long ll;
#define vi vector<int>
using namespace std;

int dX[4] = { 0, 0, -1, 1 };
int dY[4] = { -1, 1, 0, 0 };
int R, C, M;
int main() {
	cin >> R >> C >> M;
	vi X(R, 0), Y(C, 0);
	set<pair<int, int>> has;
	for (int i = 0; i < M; i++) {
		int r, c;
		cin >> r >> c;
		r--; c--;
		X[r]++; Y[c]++;
		has.insert({ r, c });
	}
	int mxx = 0, mxy = 0;
	vi xs, ys;
	for (int i = 0; i < R; i++) {
		mxx = max(mxx, X[i]);
	}
	for (int j = 0; j < C; j++) {
		mxy = max(mxy, Y[j]);
	}
	for (int i = 0; i < R; i++) {
		if (X[i] == mxx) {
			xs.push_back(i);
		}
	}
	for (int j = 0; j < C; j++) {
		if (Y[j] == mxy) {
			ys.push_back(j);
		}
	}
	ll L1 = xs.size();
	ll L2 = ys.size();
	if (L1 * L2 > M) {
		cout << mxx + mxy << '\n';
		return 0;
	}
	for (int i = 0; i < L1; i++) {
		for (int j = 0; j < L2; j++) {
			pair<int, int> chk = { xs[i], ys[j] };
			if (has.find(chk) == has.end()) {
				cout << mxx + mxy << '\n';
				return 0;
			}
		}
	}
	cout << mxx + mxy - 1 << '\n';
}