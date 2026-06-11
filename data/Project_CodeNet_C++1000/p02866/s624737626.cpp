#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
using pll=pair<ll,ll>;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 998244353

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	int N;
	cin >> N;
	vector<int> D(N);
	map<int, int> mp;
	rep(i,N) {
		cin >> D[i];
		mp[D[i]]++;
	}
	int maxi = -1;
	rep(i,N) chmax(maxi, D[i]);
	if(D[0] != 0 || mp[0] != 1) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1;
	for(int i=1; i<=maxi; i++) {
		rep(j, mp[i]) {
			ans *= mp[i-1];
			ans %= MOD;
		}
	}
	cout << ans << endl;
	

  return 0;
}
