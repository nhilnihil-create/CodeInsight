#include <bits/stdc++.h>

using namespace std;

#define int 		long long
#define endl 		"\n"
#define mod 		1000000007
#define inf 		1e12
#define IOS 		ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)


int32_t main() {

	IOS;

	int h, w, m;
	cin >> h >> w >> m;

	vector<int> row(h, 0), col(w, 0);
	set<pair<int, int>> target;
	int r, c;

	for (int i = 0; i < m; i++) {
		cin >> r >> c;
		r--, c--;

		row[r]++;
		col[c]++;
		target.insert({r, c});
	}

	int maxRow = 0, maxCol = 0;

	for (int x : row)
		maxRow = max(maxRow, x);

	for (int x : col)
		maxCol = max(maxCol, x);

	vector<int> rowCandidate, colCandidate;

	for (int i = 0; i < h; i++)
		if (row[i] == maxRow)
			rowCandidate.push_back(i);

	for (int j = 0; j < w; j++)
		if (col[j] == maxCol)
			colCandidate.push_back(j);

	int ans = maxRow + maxCol - 1;

	for (int r : rowCandidate) {
		for (int c : colCandidate) {
			if (target.find({r, c}) == target.end()) {
				ans++;
				break;
			}
		}
		if (ans == maxRow + maxCol)
			break;
	}

	cout << ans;

	return 0;
}