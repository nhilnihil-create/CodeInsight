#include <iostream>
#include <set>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	set<int> st[26];
	for (int i = 0; i < s.size(); i++) {
		st[s[i]-'a'].insert(i);
	}
	long long ans = 0, p = 0;
	for (int i = 0; i < t.size(); i++) {
		int x = t[i] - 'a';
		if (st[x].empty()) {
			cout << -1 << endl;
			return 0;
		}
		auto itr = st[x].lower_bound(p);
		if (itr == st[x].end()) {
			ans += s.size() - p;
			p = 0;
			p += *st[x].begin() + 1;
			ans += p;
		} else {
			ans += *itr - p + 1;
			p = *itr + 1;
		}

	}
	cout << ans << endl;
	return 0;
}