#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	ll sum = 0;
	vector<ll> a(n), rui(n+1, 0);
	rep(i,n){
		cin >> a[i];
		rui[i+1] = rui[i] + a[i];
		sum += a[i];
	}
	ll ans = 1e18;
	for(int i = 0; i <= n; ++i){
		ll x = rui[i];
		ll y = sum - rui[i];
		ll cost = llabs(x - y);
		chmin(ans, cost);
	}
	cout << ans << endl;
	return 0;
}