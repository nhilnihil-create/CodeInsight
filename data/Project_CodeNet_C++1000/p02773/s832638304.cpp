#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		mp[s]++;
	}
	int maxCount = 0;
	for (auto u : mp) {
		maxCount = max(maxCount, u.second);
	}
	for (auto u : mp) {
		if (maxCount == u.second) {
			cout << u.first << endl;
		}
	}
    return 0;
}