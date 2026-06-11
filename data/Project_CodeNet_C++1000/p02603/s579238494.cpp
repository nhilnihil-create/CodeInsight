#include <bits/stdc++.h>
using ll = long long;

signed main(){
	int n;
	std::cin >> n;
	std::vector<ll> a(n);
	for(int i = 0; i < n; i++) std::cin >> a[i];
	ll ans = 1000, now = a[0];
	for(int i = 1; i < n; i++){
		if(a[i] > now){
			ans += (ans / now) * (a[i] - now);
			now = a[i];
		}
		if(a[i] < now) now = a[i];
	}
	std::cout << ans << std::endl;
}
