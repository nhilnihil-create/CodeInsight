#include "bits/stdc++.h"
using namespace std;

using ll = long long;

signed main(){
	ll n,x,t;
	cin >> n >> x >> t;

	ll ans = (n % x == 0) ? n/x : (n/x)+1 ;
	cout << ans*t << "\n";

	return 0;
}