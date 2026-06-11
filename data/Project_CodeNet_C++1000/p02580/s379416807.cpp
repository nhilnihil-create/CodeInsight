// Problem Code: abc176_e

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int bomber(int H, int W, int M, vector<int>& h, vector<int>& w) {
	int max_bombs, r, c;
	set<int> seen;
	vector<int> rows(H), cols(W);
	
	for (int i = 0; i < M; i++) {
		rows[h[i]]++;
		cols[w[i]]++;
	}
	
	r = distance(rows.begin(), max_element(rows.begin(), rows.end()));
	max_bombs = rows[r];
	for (int i = 0; i < M; i++)
		if (h[i] == r)
			seen.insert(w[i]);
	
	for (c = 0; c < W; c++) {
		int bombs = rows[r] + cols[c] - seen.count(c);
		max_bombs = max(bombs, max_bombs);
	}
	
	seen.clear();
	c = distance(cols.begin(), max_element(cols.begin(), cols.end()));
	max_bombs = max(max_bombs, cols[c]);
	for (int i = 0; i < M; i++)
		if (w[i] == c)
			seen.insert(h[i]);
	
	for (r = 0; r < H; r++) {
		int bombs = rows[r] + cols[c] - seen.count(r);
		max_bombs = max(bombs, max_bombs);
	}
	
	return max_bombs;
}

int main() {
	int H, W, M;
	cin >> H >> W >> M;
	vector<int> h(M), w(M);
	for (int i = 0; i < M; i++) {
		cin >> h[i] >> w[i];
		h[i]--, w[i]--;
	}
	cout << bomber(H, W, M, h, w);
	return 0;
}