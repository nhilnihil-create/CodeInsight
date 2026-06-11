#include <bits/stdc++.h> 
using namespace std;

void print(vector<vector<int>> arr) {
	for (int i = 0; i < (int)arr.size(); ++i) {
		for (int j = 0; j < (int)arr[0].size(); ++j) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	vector<vector<int>> up(n, vector<int> (m, -1));
	vector<vector<int>> down(n, vector<int> (m, n));
	vector<vector<int>> left(n, vector<int> (m, -1));
	vector<vector<int>> right(n, vector<int> (m, m));
	
	for (int i = 0; i < n; ++i) {
		if (s[i][0] == '#')left[i][0] = 0;
		for (int j = 1; j < m; ++j) {
			left[i][j] = left[i][j - 1];
			if (s[i][j] == '#')left[i][j] = j;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		if (s[i][m - 1] == '#')right[i][m - 1] = m - 1;
		for (int j = m - 2; j >= 0; --j) {
			right[i][j] = right[i][j + 1];
			if (s[i][j] == '#')right[i][j] = j;
		}
	}
	for (int i = 0; i < m; ++i) {
		if (s[0][i] == '#')up[0][i] = 0;
		for (int j = 1; j < n; ++j) {
			up[j][i] = up[j - 1][i];
			if (s[j][i] == '#')up[j][i] = j;
		}
	}
	
	for (int i = 0; i < m; ++i) {
		if (s[n - 1][i] == '#')down[n - 1][i] = n - 1;
		for (int j = n - 2; j >= 0; --j) {
			down[j][i] = down[j + 1][i];
			if (s[j][i] == '#')down[j][i] = j;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '.') {
				int x = 1;
				x += max(0, i - up[i][j] - 1);
				x += max(0, down[i][j] - i - 1);
				x += max(0, j - left[i][j] - 1);
				x += max(0, right[i][j] - j - 1);
				ans = max(ans, x);
			}
		}
	}
	
	cout << ans;
}
