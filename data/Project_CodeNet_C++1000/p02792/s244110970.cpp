#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<vector<int>>nini(9, vector<int>(9,0));
	for (int i = 1; i <= n; i++) {
		string x = to_string(i);
		int a = x.at(0) - '0';
		int b = x.at(x.length() - 1) - '0';
		if (a == 0 || b == 0)continue;
		a--, b--;
		nini.at(a).at(b)++;
	}
	ll ans = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)ans += nini.at(i).at(j) * nini.at(j).at(i);
	}
	cout << ans << endl;
}