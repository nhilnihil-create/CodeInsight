#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define INF 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;

	vector<pair<ll,ll>> AB(N);
	rep(i,N){
		cin >> AB[i].second >> AB[i].first;
	} 

	sort(AB.begin(),AB.end());

	ll now = 0;
	rep(i,N){
		now += AB[i].second;
		if(now > AB[i].first){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}