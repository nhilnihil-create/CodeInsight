#include <bits/stdc++.h>
using namespace std;

int main() {
	int w, h,ans=0,tmp;
	cin >> h >> w;
	vector<vector<char>> m(h, vector<char>(w));
	vector<vector<int>> light(h, vector<int>(w,0)),L(h,vector<int>(w,0)),R(h,vector<int>(w,0)),U(h,vector<int>(w,0)),D(h,vector<int>(w,0));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> m.at(i).at(j);
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (m.at(i).at(j) == '#') {
				L.at(i).at(j) = 0;
			}
			else if (j == 0) {
				L.at(i).at(j) = 1;
			}
			else if (j > 0) {
				L.at(i).at(j) = L.at(i).at(j - 1) + 1;
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = w - 1; j > -1; j--) {
			if (m.at(i).at(j) == '#') {
				R.at(i).at(j) = 0;
			}
			else if (j == w - 1) {
				R.at(i).at(j) = 1;
			}
			else if (j < w - 1) {
				R.at(i).at(j) = R.at(i).at(j + 1) + 1;
			}
		}
	}
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (m.at(j).at(i) == '#') {
				D.at(j).at(i) = 0;
			}
			else if (j == 0) {
				D.at(j).at(i) = 1;
			}
			else if (j > 0) {
				D.at(j).at(i) = D.at(j - 1).at(i) + 1;
			}
		}
	}
	for (int i = 0; i < w; i++) {
		for (int j = h - 1; j > -1; j--) {
			if (m.at(j).at(i) == '#') {
				U.at(j).at(i) = 0;
			}
			else if (j == h - 1) {
				U.at(j).at(i) = 1;
			}
			else if (j < h - 1) {
				U.at(j).at(i) = U.at(j + 1).at(i) + 1;
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			tmp = L.at(i).at(j) + R.at(i).at(j) + U.at(i).at(j) + D.at(i).at(j) - 3;
			if (tmp > ans) {
				ans = tmp;
			}
		}
	}
	cout << ans << endl;
}