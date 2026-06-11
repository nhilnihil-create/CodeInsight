#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<int> ans;
	for (int i = n; i > 0; ) {
		int p = i;
		i -= m;
		if (i < 0) i = 0;
		while (s[i] != '0') i++;
		if (i == p) {
			cout << -1 << endl;
			return 0;
		}
		ans.push_back(p-i);
	}
	reverse(ans.begin(), ans.end());
	for (int e : ans) cout << e << endl;
	return 0;
}