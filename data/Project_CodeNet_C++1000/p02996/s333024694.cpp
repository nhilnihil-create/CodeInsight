#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N;

int main(){
	cin >> N;

	vector<pair<ll, ll> >BA(N);

	rep(i, N) {
		cin >> BA[i].second >> BA[i].first;
	}

	sort(BA.rbegin(), BA.rend());


	ll cur = 1e15;

	rep(i, N) {
		ll end = BA[i].first;
		ll t = BA[i].second;

		if(cur > end) {
			cur = end;
		}

		cur -= t;
	}

	if(cur >= 0) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
