#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

// dp[i][S]
ll dp[2200][2200];

int main(){
	dp[0][0] = 1;
	ll sum; cin >> sum;
	ll ans = 0;
	for( int i = 0; i < 2100; ++i ){
		ll pre = 0;
		for( int s = 0; s <= sum-3; ++s ){
			pre += dp[i][s];
			pre %= mod;
			dp[i+1][s+3] = pre;
		}
		ans += dp[i+1][sum];
		ans %= mod;
		/*
		for( int s = 0; s <= sum; ++s ){
			dp[i+1][s] = Σ dp[i][0からs-3まで];			
		}
		*/
	}
	cout << ans << endl;
}