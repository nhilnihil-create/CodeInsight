#include <bits/stdc++.h>
using namespace std;

//https://atcoder.jp/contests/abc146/tasks/abc146_f

int n, m;
string s;
vector<int> ans;

int main() {
	cin >> n >> m >> s;
	for (int i = n - 1, c = n, l = n; i >= 0; --i) {
		if (s[i] == '0')
			l = i;
		if (c - i == m || !i) {
			if (l != c) {
				ans.push_back(c - l);
				c = l;
			} else {
				cout << -1 << endl;
				return 0;
			}
		}

	}

	for (int i = ans.size() - 1; i >= 0; --i)
		cout << ans[i] << (i ? " " : "\n");

}
