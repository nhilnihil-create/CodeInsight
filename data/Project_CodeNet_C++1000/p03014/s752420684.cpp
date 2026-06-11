#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>>s(h + 2, vector<int>(w + 2, -1));
	for (int i = 1; i < h + 1; i++) {
		for (int j = 1; j < w + 1; j++) {
			char x;
			cin >> x;
			if (x == '#')s.at(i).at(j) = -1;
			else s.at(i).at(j) = 0;
		}
	}
	vector<vector<int>>yoko = s;
	vector<vector<int>>tate = s;
	for (int i = 0; i < h + 2; i++) {
		for (int j = 0; j < w + 2; j++) {
			if (yoko.at(i).at(j) == -1)continue;
			else {
				if (yoko.at(i).at(j - 1) != -1)yoko.at(i).at(j) = yoko.at(i).at(j - 1) + 1;
				else yoko.at(i).at(j) = 1;
			}
		}
		for (int j = w + 1; j >= 0; j--) {
			if (yoko.at(i).at(j) == -1)continue;
			else {
				if (yoko.at(i).at(j + 1) == -1)continue;
				else yoko.at(i).at(j) = yoko.at(i).at(j + 1);
			}
		}
	}
	for (int i = 0; i < w + 2; i++) {
		for (int j = 0; j < h + 2; j++) {
			if (tate.at(j).at(i) == -1)continue;
			else {
				if (tate.at(j - 1).at(i) != -1)tate.at(j).at(i) = tate.at(j - 1).at(i) + 1;
				else tate.at(j).at(i) = 1;
			}
		}
		for (int j = h + 1; j >= 0; j--) {
			if (tate.at(j).at(i) == -1)continue;
			else {
				if (tate.at(j + 1).at(i) == -1)continue;
				else tate.at(j).at(i) = tate.at(j + 1).at(i);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < h + 2; i++) {
		for (int j = 0; j < w + 2; j++) {
			ans = max(ans, yoko.at(i).at(j) + tate.at(i).at(j));
		}
	}
	cout << ans - 1<< endl;
}