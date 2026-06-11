#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	
	ll x,k,d;
	cin >> x >> k >> d;
	x = abs(x);
	ll t = min(k, x/d);
	k -= t;
	x -= t*d;
	
	if(k%2 == 0) cout << x;
	else cout << d - x;
	return 0;
}
