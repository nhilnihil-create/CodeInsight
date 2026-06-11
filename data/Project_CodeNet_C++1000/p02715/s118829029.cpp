#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

const ll mod = 1000000007;

ll modpow(ll x, ll n){
    if(n == 0) return (ll)1;
    if(n % 2 == 0) return modpow(x * x % mod, n / 2);
    else return x * modpow(x, n - 1) % mod;
}

int main() {
    ll n, k;
    cin >> n >> k;
    
    vector<ll> cnt(k, 0);
    for(int x = k; x > 0; x--){
        ll sum = modpow(k / x, n);
        for(int y = 2 * x; y <= k; y += x){
            sum = (sum - cnt[y-1] + mod) % mod;
        }
        cnt[x-1] = sum;
    }

    ll ans = 0;
    rep(i, k)ans = (ans + (cnt[i] * (i + 1)) % mod) % mod;
    cout << ans << endl;
}