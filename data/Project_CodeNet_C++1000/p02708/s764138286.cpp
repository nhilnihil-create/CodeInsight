#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;

#define SIZ 1000000000
#define mod 1000000007

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// D from 163
	ll n,k;
	cin >> n >> k;
	
	ll ans = 0;
	for(ll i = k - 1; i <= n; i++){
		ans += ((i + 1)*(n - i)) + 1;
		ans = ans%mod;
	}
	
	cout << ans << "\n";
}