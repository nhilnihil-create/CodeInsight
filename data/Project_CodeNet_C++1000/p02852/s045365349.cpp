#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;


int main(void) {
	int n, m, i, g[100003], t, r, b;
	string s;
	vector<int> ans;

	cin >> n >> m >> s;

	for (i = n; i >= 0; i--) {
		if (s[i] == '0') t = i;
		g[i] = t;
	}

	r = n;
	while (r > 0) {
		b = g[max(0, r - m)];
		if (b >= r) {
			cout << -1 << endl;
			return 0;
		}
		ans.push_back(r - b);
		r = b;
	}

	for (i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << ' ';
	}
	cout << endl;

	return 0;
}