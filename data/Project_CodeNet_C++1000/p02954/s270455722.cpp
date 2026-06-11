#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<int> ans;
	int cntr = 0, cntl = 0;
	int indr, indl;
	for (int i = 0; i < s.size(); i++) {
		ans.push_back(0);
		if (s[i] == 'R')
			cntr++;
		else if (s[i] == 'L')
			cntl++;
		if (s[i] == 'R' && s[i + 1] == 'L') {
			indr = i;
			indl = i + 1;
		} else if ((s[i] == 'L' && s[i + 1] == 'R') || i == s.size() - 1) {
			if (cntr % 2 == 0) {
				ans[indl] += cntr / 2;
				ans[indr] += cntr / 2;
			} else {
				ans[indl] += cntr / 2;
				ans[indr] += cntr / 2 + 1;
			}
			if (cntl % 2 == 0) {
				ans[indl] += cntl / 2;
				ans[indr] += cntl / 2;
			} else {
				ans[indl] += cntl / 2 + 1;
				ans[indr] += cntl / 2;
			}
			cntr = 0;
			cntl = 0;
		}
	}
	for (int i = 0; i < s.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
