#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i < (int)(n); i++)
#define Sort(a) sort(a.begin(), a.end())
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;

ll mod = 1000000007;

ll modpow(ll x, ll n) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll modcmb(int n, int r) {
    ll ans = 1;
    rep(i, r) {
        ans *= (n-i) * modpow(i+1, mod-2) % mod;
        ans %= mod;
    }
    return ans;
}

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    ll all_sum = modpow(2, n);
    ll exclusion = modcmb(n, a) + modcmb(n, b);
    all_sum = (all_sum+mod)%mod;
    exclusion = (exclusion+mod)%mod;
    ll ans = all_sum - exclusion;
    ans = (ans+mod)%mod;
    cout << ans-1 << endl;
    return 0;
}