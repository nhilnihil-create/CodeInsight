#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	ll n,k;
	cin >> n >> k;
	vector<ll> a(n);
	vector<ll> f(n);
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> f[i];
	sort(a.rbegin(),a.rend());
	sort(f.begin(),f.end());
	ll l = -1;
	ll r = 1e+18;
	while(r - l > 1){
		ll m = (l+r)/2;
		ll count = 0;
		rep(i,n){
			count += max(ll(0), a[i] - m/f[i]);
		}
		if(count > k){
			l = m;
		}else{
			r = m;
		}
	}
	cout << r << endl;
    return 0;
}