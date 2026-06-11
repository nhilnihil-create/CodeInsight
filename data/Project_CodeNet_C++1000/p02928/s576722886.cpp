#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

const ll mod = 1000000007;
int main(){
	ll n,k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	ll p = 0;
	ll q = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if(a[i] > a[j]) p++;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if(a[i] > a[j]) q++;
		}
	}
	ll c1 = k;
	ll c2 = k*(k-1)/2LL % mod;
	ll ans = (c1*p + c2*q) % mod;
	cout << ans << endl;
    return 0;
}