#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
//const ll INF = 1LL<<60;
int INF = numeric_limits<int>::max();

int main(int, char**) {
	string s, t; cin >> s >> t;
	vector<vector<int>> M(26, vector<int>(0));
	for (int i=0; i<s.size(); i++) {
		int c = s[i] - 'a';
		M[c].push_back(i);
	}
	ll cnt = 0;
	int now = INF;
	for (int i=0; i<t.size(); i++) {
		int c = t[i] - 'a';
		if (M[c].size()==0) {
			cout << -1 << endl;
			return 0;
		}
		auto itr = upper_bound(M[c].begin(), M[c].end(), now);
		if (itr==M[c].end()) {
			cnt++;
			now = M[c][0];
		} else {
			now = *itr;
		}
	}
	ll ret = (cnt - 1) * s.size() + now + 1;
	cout << ret << endl;
	return 0;
}