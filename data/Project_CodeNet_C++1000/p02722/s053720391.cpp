#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	ll n;
	cin >> n;
	int ans = 0;
	for(ll i = 1; i * i <= n-1; i++){
		if((n-1) % i != 0) continue;
		if(i != 1)ans++;
		ll j = (n-1)/i;
		if(i != j) ans++;
	}
	// cerr << ans << endl;
	for(ll i = 1; i * i <= n; i++){
		if(n % i != 0) continue;
		ll j = n/i;
		ll t = n;
		while(t % j == 0 && t > 1){
			t /= j;
		}
		if(t % j == 1) ans++;
		if(i == 1 || i == j) continue;
		t = n;
		while(t % i == 0 && t > 1){
			t /= i;
		}
		if(t % i == 1) ans++;
	}
	cout << ans << endl;
	return 0;
}