#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	s += s;		//s.size()分だけオフセットを足したものもsidxに格納するためにsを連結

	vector<vector<ll>> sidx(26, vector <ll> ());
	for (ll ii = 0; ii < s.size(); ++ii){
		ll ch = s[ii] - 'a';
		sidx[ch].push_back(ii);
	}

	ll now = -1;
	ll ans = 0;
	ll n = s.size() / 2;
	for (int ii = 0; ii < t.size(); ++ii){
		ll ch = t[ii] - 'a';
		//tの文字がsに含まれていなかったら諦める
		if (sidx[ch].size() == 0){
			cout << -1 << endl;
			return 0;
		}
		//nowより大きい最小のsidx[ch]を求める
		auto itr = upper_bound(sidx[ch].begin(), sidx[ch].end(), now);
		ll idx = sidx[ch][itr - sidx[ch].begin()];
		//値を更新
		ans += idx - now;
		if (idx < n) {
			now = idx;
		} else {
			now = idx - n;
		}
	}

	cout << ans << endl;

	return 0;
}
