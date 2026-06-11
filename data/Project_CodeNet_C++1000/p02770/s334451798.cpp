#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	Int k, q; cin >> k >> q;
	vector<Int> d(k);
	for(auto &i:d) cin >> i;
	while(q--){
		Int n, x, m; cin >> n >> x >> m;
		vector<Int> b(d);
		for(auto &i:b) i %= m;
		Int q = (n-1) / k;
		Int r = n-1 - k*q;
		Int ans = n-1;
		for(Int i=0; i<k; ++i)
			if(b[i] == 0)
				ans -= q + (i < r ? 1 : 0);
		Int c = x;
		for(Int i=0; i<k; ++i)
			c += b[i] * (q + (i < r ? 1 : 0));
		ans -= c / m - x / m;
		cout << ans << "\n";
	}
}