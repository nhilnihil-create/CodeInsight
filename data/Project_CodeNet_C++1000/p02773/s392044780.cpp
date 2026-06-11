#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string, int> mp;
	int n;
	cin >> n;
	int max_votes = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		mp[s]++;
		max_votes = max(mp[s], max_votes);
	}
	vector<string> bests;
	for (auto const& x : mp) {
		if (x.second == max_votes)
			bests.push_back(x.first);
	}
	sort(bests.begin(), bests.end());
	for (string s : bests)
		cout << s << endl;
	return 0;
}