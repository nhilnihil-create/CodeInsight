#include "bits/stdc++.h"

//#include <atcoder/all>

using namespace std;
//using namespace atcoder;

//#define int long long
#define ll long long

ll INF = (1LL << 60);
int mod = 998244353;
using P = pair<ll, ll>;

signed main() {
	string s; cin >> s;
	map<int, int>mp;
	for (int i = 0; i < s.size(); i++) {
		mp[s[i]]++;
	}
	bool ok = true;
	if (mp.size() == 2) {
		for (auto p : mp) {
			if (p.second != 2)ok = false;
		}
	}
	else {
		ok = false;
	}
	if (ok)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

