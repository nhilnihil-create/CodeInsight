#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	int n = s.size();
	vector<vector<int>> v(n, vector<int>(26, -1));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) {
			if (j + 'a' == s[i]) {
				v[i][j] = i;
			} else {
				if (i + 1 < n) v[i][j] = v[i + 1][j];
			}
		}
	}
	int res = 0;
	int m = t.size();
	int index = 0;
	for (int i = 0; i < m; i++) {
		if (index == 0 && v[index][t[i] - 'a'] == -1) {
			cout << -1 << endl;
			return 0;
		}

		if (index == 0) res++;
		if (v[index][t[i] - 'a'] == -1) {
			index = 0;
			res++;
			if (v[index][t[i] - 'a'] == -1) {
				cout << -1 << endl;
				return 0;
			}
		}
		index = v[index][t[i] - 'a'] + 1;
		if (i == m - 1) {
			cout << (long long int)(res - 1) * n + index << endl;
			return 0;
		}
		if (index >= n) index = 0;
	
	}
	cout << res << endl;
}
