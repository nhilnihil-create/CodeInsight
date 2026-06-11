#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N;

int main(){
	cin >> N;
	// num, pos
	vector<pair<ll, ll> > P(N);
	rep(i, N) {
		ll tmp;
		cin >> tmp;
		P.push_back(make_pair(tmp, i));
	}

	sort(P.rbegin(), P.rend());

	set<ll> pos;

	ll ans = 0;
	rep(i, N) {
		ll cur = P[i].second;
		ll firstLeft = -1, secondLeft = -1;
		ll firstRight = N, secondRight = N;

		pos.insert(cur);
		set<ll>::iterator it = pos.find(cur);

		if(it != pos.begin()) {
			it--;
			firstLeft = *it;
			if(it != pos.begin()) {
				it--;
				secondLeft = *it;
				it++;
			}
			it++;
		}
		it++;
		if(it != pos.end()) {
			firstRight = *it;
			it++;
			if(it != pos.end()) {
				secondRight = *it;
			}
		}

		ll tmp = 0;
		tmp += (firstLeft - secondLeft) * (firstRight - cur);
		tmp += (cur - firstLeft) * (secondRight - firstRight);
		tmp *= P[i].first;
		ans += tmp;

		//cout << "cur = " << cur << " firstleft " << firstLeft << " secondLeft " << secondLeft << " firstRight " << firstRight << " secondRight " << secondRight << endl;
	}
	cout << ans << endl;
}

