#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, m;
    cin >> n >> m;
    vector<bool> v(n+1, false);
    rep(i, 0, m) {
        ll a;
        cin >> a;
        v[a] = true;
    }
    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    const ll mod = 1000000000 + 7;
    rep(i, 0, n) {
        if(v[i]) continue;
        if(!v[i+1]){
            dp[i+1] += dp[i];
            dp[i+1] %= mod;
        }
        if(!v[i+2] && i+2 <= n) {
            dp[i+2] += dp[i];
            dp[i+2] %= mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}