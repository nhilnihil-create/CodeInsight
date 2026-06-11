#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

int main() {
	string s, t;
	cin >> s >> t;
	vector<set<int>> v(26);
	int n = int(s.size());
	rep(i, n) {
		v[s[i] - 'a'].insert(i + 1);
	}
	ll ans = 0;
	int id = 0;
	int m = int(t.size());
	rep(i, m) {
		int c = t[i] - 'a';
		if (v[c].empty()){
			cout << -1 << endl;
			return 0;
		}
		auto itr = v[c].lower_bound(id+1);
		if (itr == v[c].end()) {
			itr = v[c].begin();
			ans += ll(n - id + *itr);
		} else {
			ans += ll(*itr - id);
		}
		id = *itr;
	}
	cout << ans << endl;
	return 0;
}