#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	vector<ll> l(n+1, 0), r(n+1, 0);
	rep(i,n) l[i+1] = l[i] + a[i];
	for(int i = n; i > 0; --i){
		r[i-1] = r[i] + a[i-1];
	}
	ll ans = 1e18;
	rep(i,n+1){
		chmin(ans, abs(l[i] - r[i]));
	}
	cout << ans << endl;
	return 0;
}