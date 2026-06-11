#include "bits/stdc++.h"
using namespace std;

class HandV {
private:
	int h, w, k;
	int black = 0;
	int ans = 0;

	vector<string> board;
	vector<int> hBlack;
	vector<bool> hDrawn;

public:
	HandV(int _h, int _w, int _k) {
		h = _h;
		w = _w;
		k = _k;

		board = vector<string>(h);
		hBlack = vector<int>(h, 0);
		hDrawn = vector<bool>(h, false);
	}

	void setBoard() {
		for (int i = 0; i < h; i++) {
			cin >> board.at(i);
			for (auto e : board.at(i)) {
				if (e == '#') {
					black++;
					hBlack.at(i)++;
				}
			}
		}
		if (black == k) ans++;
	}

	void drawH(int _h) {
		if (black - hBlack.at(_h) < k || _h >= h) return;
		else if (black - hBlack.at(_h) == k) ans++;

		black -= hBlack.at(_h);
		hDrawn.at(_h) = true;
		for (int i = _h + 1; i < h; i++) {
			drawH(i);
		}

		for (int i = 0; i < w; i++) {
			drawW(i);
		}

		hDrawn.at(_h) = false;
		black += hBlack.at(_h);
	}

	void drawW(int _w) {

		int wBlack = 0;

		for (int i = 0; i < h; i++) {
			if (hDrawn.at(i) == false && board.at(i).at(_w) == '#') {
				wBlack++;
			}
		}

		if (black - wBlack < k) return;
		else if (black - wBlack == k) ans++;

		black -= wBlack;

		for (int i = _w + 1; i < w; i++) {
			drawW(i);
		}

		black += wBlack;
	}

	void solve() {
		setBoard();

		for (int i = 0; i < h; i++) {
			drawH(i);
		}

		for (int i = 0; i < w; i++) {
			drawW(i);
		}

		cout << ans << endl;
	}
};


int main() {
	int h, w, k;
	cin >> h >> w >> k;

	HandV hv(h, w, k);
	hv.solve();
}