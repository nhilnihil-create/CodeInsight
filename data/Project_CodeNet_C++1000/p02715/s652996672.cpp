#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 1e5 + 5;
ll dp[N];
ll mod = 1e9 + 7;
ll binpow(ll x, ll p){
        if (p == 0) return 1;
        if (p == 1) return x;
        ll t = binpow(x, p/2) % mod;
        if (p % 2 == 0) return t * t % mod;
        else return t * t % mod * x % mod;
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (fopen("VLJUM.INP", "r")){
                freopen("VLJUM.INP", "r", stdin);
                freopen("VLJUM.OUT", "w", stdout);
        }
        ll n, k;
        cin >> n >> k;
        ll ans = 0;
        for (int i = k; i >= 1; i--){
                dp[i] = binpow(k / i, n) % mod;
                for (int j = i + i; j <= k; j += i){
                        dp[i] = (dp[i] - dp[j] + mod) % mod;
                }
                ans = (ans + dp[i] * i) % mod;
        }
        cout << ans;
}
/*
*/
