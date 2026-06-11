#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string S, T;
	cin >> S >> T;
	map<char, vector<int>> CharMap;
	for (int i = 0; i < S.length(); i++) CharMap[S[i]].push_back(i);
	long long ans = 0, now = 0;
	for (char c : T) {
		if (CharMap.find(c) == CharMap.end()) {
			cout << -1 << endl;
			return 0;
		}
		auto itr = lower_bound(CharMap[c].begin(), CharMap[c].end(), now);
		if (itr == CharMap[c].end()) {
			ans += S.length();
			itr = lower_bound(CharMap[c].begin(), CharMap[c].end(), 0);
		}
		now = (long long)*itr + 1;
	}
	ans += now;
	cout << ans << endl;
}