#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod  = 1e9 + 7;
const ll INF = 1e14;


void solve(){

    ll n; cin >> n;
    vector<ll> arr (n);
    for(ll& it : arr) cin >> it;
    vector<ll> dp (n, 0);
    for(ll i = 0; i < n; ++i)
        if(i - arr[i] >= 0) dp[i-arr[i]]++;
    ll ans = 0;
    for(ll i = 0; i < n; ++i)
        if(i + arr[i] < n) ans += dp[i+arr[i]];
    cout << ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    //int test; cin >> test;
    //for(int t = 1; t <= test; ++t){
        solve();    
    //}

	return 0;
}

