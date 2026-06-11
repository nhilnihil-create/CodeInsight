#include <bits/stdc++.h>
using ll = long long;

signed main(){
	int n;
	std::cin >> n;
	std::vector<ll> a(n);
	for(int i = 0; i < n; i++) std::cin >> a[i];
	ll ans = 1000;
	for(int i = 0; i < n - 1; i++){
		if(a[i] < a[i + 1]){
			ans += (a[i + 1] - a[i]) * (ans / a[i]);
		}
	}
	std::cout << ans << std::endl;
}