#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 2019;

int main(){
	ll l,r;
	cin >> l >> r;
	ll ans = 2018;
	ll a = 0;
	r = min(r,l+4039);
	for(ll i = l; i <= r; i++){
		for(ll j = i+1; j <= r; j++){
			a = i%mod*j%mod%mod;
		ans = min(a,ans);
		}
	}
	cout << ans << endl;
}

// cout << fixed << setprecision(15) <<  << endl;