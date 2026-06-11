#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
	
ll mod = 1e9 + 7;
 
int main(){
	ll n; cin >> n;
    ll dp[n + 1] = {0};
    dp[0] = 1;
    for(ll i = 3; i <= n; ++i){
        for(ll j = 3; j <= n; ++j){
            if(i - j >= 0){
                dp[i] += dp[i - j];
                dp[i] %= mod;
            }
        }
    } 
    cout << dp[n];
    return 0;
}
