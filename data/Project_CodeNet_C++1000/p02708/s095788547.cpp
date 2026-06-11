#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll mod = 1000000007;

int main(){
	ll n, k;
	cin >> n >> k;
	ll ans = 1;
	vector<ll> a(n+1);
	ll l = 0;
	rep(i, n){
		l += i;
		if(l >= mod) l %= mod;
//		cout << l << endl;
		a.at(i) = l;
	}
	for(ll i=k; i<=n; i++){
		ans += i*n - a.at(i-1) - (a.at(i-1) - 1);
//		cout << i*n - a.at(i-1) << ' ' << a.at(i-1) - 1 << endl;
		if(ans >= mod) ans %= mod;
	}
	cout << ans << endl;
	return 0;
}