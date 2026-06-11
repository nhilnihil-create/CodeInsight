#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N;
	cin >> N;

	vector <ll> plus;
	vector <ll> minus;
	for (int ii = 0; ii < N; ++ii){
		ll val;
		cin >> val;
		if (val >= 0){
			plus.push_back(val);
		} else {
			minus.push_back(val);
		}
	}

	ll ans;
	vector <pair<ll, ll>> s;
	if (minus.size() == 0){
		sort(plus.begin(), plus.end());
		ll tmp = plus[0];
		for (int ii = 1; ii < plus.size()-1; ++ii){
			s.push_back(make_pair(tmp, plus[ii]));
			tmp -= plus[ii];
		}
		s.push_back(make_pair(plus.back(), tmp));
		ans = plus.back() - tmp;
	} else if (plus.size() == 0) {
		sort(minus.rbegin(), minus.rend());
		ll tmp = minus[0];
		for (int ii = 1; ii < minus.size(); ++ii){
			s.push_back(make_pair(tmp, minus[ii]));
			tmp -= minus[ii];
		}
		ans = tmp;
	} else {
		//plusの要素が残り1個になるまでの処理
		ll tmp = minus.back();
		for (int ii = 0; ii < plus.size()-1; ++ii){
			s.push_back(make_pair(tmp, plus[ii]));
			tmp -= plus[ii];
		}
		//そのあとの処理
		s.push_back(make_pair(plus.back(), tmp));
		tmp = plus.back() - tmp;
		for (int ii = 0; ii < minus.size()-1; ++ii){
			s.push_back(make_pair(tmp, minus[ii]));
			tmp -= minus[ii];
		}
		ans = tmp;
	}

	cout << ans << "\n";
	for (int ii = 0; ii < s.size(); ++ii){
		cout << s[ii].first << " " << s[ii].second << "\n";
	}

	return 0;
}
