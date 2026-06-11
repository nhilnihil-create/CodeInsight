#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
using ll = long long;
using namespace std;

int main(){
	int n, mod; cin >> n >> mod;
	vector<ll> a(n), sum(n+1);
	for( auto &k : a ){
		cin >> k;
		--k;
	}
	sum[0] = 0;
	for( int i = 0; i < n; ++i ){
		sum[i+1] = sum[i]+a[i];
		sum[i+1] %= mod;
	}
	map<ll, vector<int>> mp;
	for( int i = 0; i <= n; ++i ){
		mp[sum[i]].push_back(i); 
	}
	ll ans = 0;
	for( auto &k : mp ){
		auto &s = k.second;
		for( int l = 0; l < s.size(); ++l ){
			int r = lower_bound(s.begin(), s.end(), s[l]+mod) - s.begin();
			ans += r-l-1;
		}
	}
	cout << ans << endl;
}