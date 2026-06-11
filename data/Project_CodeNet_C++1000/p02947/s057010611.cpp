#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	map<vector<int>, ll> freq;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		vector<int> t(26);
		for (char c: s) ++t[c-97];
		++freq[t];
	}
	ll res = 0;
	for (auto x: freq) res += x.second * (x.second - 1) / 2;
	cout << res << endl;
	return 0;
}