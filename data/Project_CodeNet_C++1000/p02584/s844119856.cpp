#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// INT VS LL

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x, k, d;
    cin >> x >> k >> d;
    ll n = x / d;
    if (x >= 0){
	    if (k <= n){
	    	ll ans = x - k * d;
	    	cout << ans << '\n';
	    }
	    else{
	    	k -= n;
	    	ll ans = x - (n * d);
	    	cout << (k % 2 == 0 ? ans : abs(ans - d)) << '\n';
	    }
	}
	else{
		n *= -1LL;
		if (k <= n){
	    	ll ans = abs(x + k * d);
	    	cout << ans << '\n';
	    }
	    else{
	    	k -= n;
	    	ll ans = x + (n * d);
	    	cout << (k % 2 == 0 ? abs(ans) : abs(ans + d)) << '\n';
	    }
	}
    // if x 
    return 0;
}