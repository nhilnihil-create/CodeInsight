#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

string s, t;
map<char, vector<int>>occ;
int find_next(int i, char c) {
	auto nxt = lower_bound(occ[c].begin(), occ[c].end(), i);
	if (nxt != occ[c].end()) return *nxt;
	if (occ[c].size() > 0) {
		return occ[c][0];
	}
	return -1;
}


int main() {
	cin >> s >> t;
	rep(i, s.size()) {
		occ[s[i]].push_back(i);
	}
	ll ans = 0;
	int now = 0;
	for(char c: t) {
		int nxt = find_next(now, c);
		if (nxt == -1) {
			ans = -1;
			break;
		}
		if (now <= nxt) ans += nxt - now + 1;
		else ans += s.size() - now + nxt + 1;
		now = (nxt + 1) % s.size();
	}
	cout << ans << endl;
}
