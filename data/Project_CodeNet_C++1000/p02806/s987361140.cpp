#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

using psi = pair<string, int>;

int main() {
	int n; cin >> n;
	vector<psi> songs(n);
	for (int i = 0; i < n; ++i)
		cin >> songs[i].first >> songs[i].second;
	string x; cin >> x;
	int res = 0; bool flg = false;
	for (int i = 0; i < n; ++i) {
		if (flg) res += songs[i].second;
		if (songs[i].first == x) flg = true;
	}
	cout << res << endl;
	return 0;
}