#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3005;
const ll mod = 998244353;
int n, s;
ll a[N], dp[N];
ll fast_pw(ll x, ll y) {
    ll ret = 1;
    for(;y;y>>=1) {
        if(y&1) ret = (ret * x) % mod;
        x = (x * x) % mod;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    dp[0] = fast_pw(2, n);
    ll inv = fast_pw(2, mod - 2);
    for(int i = 0; i < n; i++) {
        for(int j = s; j >= a[i]; j--) {
            dp[j]+=(dp[j-a[i]]*inv)%mod;
            dp[j]%=mod;
        }
    }
    cout << dp[s];
    return 0;
}