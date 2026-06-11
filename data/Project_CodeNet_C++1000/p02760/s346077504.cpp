#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 3e5 + 7;



int main() {
	fastIO;
	int grid[3][3] = {};
	map<int, pair<int, int>> pos;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int x;
			cin >> x;
			pos[x] = { i, j };
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (!pos.count(x))
			continue;
		grid[pos[x].first][pos[x].second] = 1;
	}

	bool valid = false;
	for (int i = 0; i < 3; i++) {
		valid |= grid[i][0] + grid[i][1] + grid[i][2] == 3 || grid[0][i] + grid[1][i] + grid[2][i] == 3;
	}
	valid |= grid[0][0] + grid[1][1] + grid[2][2] == 3 || grid[0][2] + grid[1][1] + grid[2][0] == 3;

	if (valid) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}