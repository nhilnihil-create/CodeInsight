#include <bits/stdc++.h>

using namespace std;

int main() {

	string s;
	cin >> s;

	vector<int> res(s.size());

	int pp = 0;
	int i = 0;
	while (1) {
		int j = 0;
		if (s[i] == 'R' && s[i + 1] == 'L') {
			int counterr = 0;
			int counterl = 0;
			j = 0;
			while (s[i + j] == 'R') {
				counterr++;
				if (i + j == 0) { break; }
				j--;
			}
			j = 1;
			while (s[i + j] == 'L') {
				counterl++;
				if (i + j == s.size()-1) { break; }
				j++;
			}
			res[i] = (counterr-1) / 2 + counterl / 2 + 1;
			res[i + 1] = (counterr) / 2 + (counterl-1) / 2 + 1;
			i = i + j-1;
		}
		i++;
		if (i > s.size() - 1) { break; }
	}

	for (i = 0; i < s.size(); i++) {
		if (i != 0) {
			cout << " " << res[i];
		}
		else {
			cout << res[i];
		}
	}
	return 0;
}