#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int R(int a, vector<bool> y) {
	int ans = 0;
	rep(i, a + 1) {
		if (y.at(a - i)) break;
		else ans++;
	}
	return ans;
}

int L(int a, vector<bool> y) {
	int ans = 0;
	for (int i = a; i < y.size(); i++) {
		if (!(y.at(i))) break;
		else ans++;
	}
	return ans;
}

int main() {
	vector<bool> y;
	string s; cin >> s;
	for (char i : s) {
		if (i == 'R') y.push_back(0);
		else y.push_back(1);
	}
	vector<int> ans(s.size(), 0);
	rep(i, s.size() - 1) {
		if (!(y.at(i)) && y.at(i + 1)) {
			int r = R(i, y); int l = L(i + 1, y);
			ans.at(i) = l / 2 + (r + 1) / 2;
			ans.at(i + 1) = r / 2 + (l + 1) / 2;
		}
	}
	for (int i : ans) cout << i << ' ';
}