#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string s, t;
	cin >> s >> t;

	vector<vector<ll>> sidx(26, vector <ll> ());
	for (ll ii = 0; ii < s.size(); ++ii){
		ll ch = s[ii] - 'a';
		sidx[ch].push_back(ii);
		sidx[ch].push_back(ii + s.size());	//s.size()分だけオフセットを足したものも格納
	}

	for (ll ch = 0; ch < 26; ++ch){
		if (sidx[ch].size() > 0){
			sort(sidx[ch].begin(), sidx[ch].end());
		}
	}

	vector <ll> sitr(26, 0);
	ll now = -1;
	ll ans = 0;
	for (int ii = 0; ii < t.size(); ++ii){
		ll ch = t[ii] - 'a';

		if (sidx[ch].size() == 0){
			cout << -1 << endl;
			return 0;
		}

		//nowより大きい最小のsidx[ch]を求める
		auto itr = upper_bound(sidx[ch].begin(), sidx[ch].end(), now);
		ll idx = sidx[ch][itr - sidx[ch].begin()];

		//値を更新
		ans += idx - now;
		if (idx < s.size()){
			now = idx;
		} else {
			now = idx - s.size();
		}
	}

	cout << ans << endl;

	return 0;
}
