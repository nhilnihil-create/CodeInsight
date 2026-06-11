#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

int main(){
	ll N, M;
	cin >> N >> M;
	vector<pair<ll, ll> >AB(N);
	rep(i, N) {
		cin >> AB[i].first >> AB[i].second;
	}

	sort(AB.rbegin(), AB.rend());

	//cost
	priority_queue<ll> Q;

	ll ans = 0;
	for(ll i = 1; i <= M; i++) {
		while(AB.size() > 0 && AB.back().first <= i) {
			Q.push(AB.back().second);
			AB.pop_back();
		}

		if(!Q.empty()) {
			ans += Q.top();
			Q.pop();
		}
	}

	cout << ans << endl;


}
