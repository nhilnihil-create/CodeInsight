#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	map<string, int> ans;
	ans["SUN"] = 7;
	ans["MON"] = 6;
	ans["TUE"] = 5;
	ans["WED"] = 4;
	ans["THU"] = 3;
	ans["FRI"] = 2;
	ans["SAT"] = 1;

	string s;
	cin >> s;

	cout << ans[s];
}