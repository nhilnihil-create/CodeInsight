#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0;i < n;i++){
        cin >> a[i];
    }

    vector<ll> dp(100,0);
    dp[0] = 1000;

    for (ll i = 1; i < n; i++){
        dp[i] = dp[i-1];
        for (ll j = 0; j < i; j++){
            ll s = dp[j]/a[j];
            ll m = (dp[j]%a[j]) + a[i]*s;
            dp[i] = max(dp[i],m);
        }
    }

    cout << dp[n-1] << endl;
    
}