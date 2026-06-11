#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	ll l, r;
	cin >> l >> r;

	r = min(r, l+2018);
	int ans = 2018;
	for(ll i = l; i <= r; i++){
		for(ll j = i+1; j<= r; j++){
			int mod = i*j%2019;
			ans = min(ans, mod);
		}
	}
	cout << ans << endl;
	return 0;
}