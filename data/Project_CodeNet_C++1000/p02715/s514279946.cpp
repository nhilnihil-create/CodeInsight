#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const ll mod = 1e9 + 7;

ll memo[100010];

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    int n, k;
    cin >> n >> k;

    ll res = 0;
    for(ll i = k; i >= 1; --i){
        ll tmp = modpow(k / i, n, mod);
        for(ll j = 2 * i; j <= k; j += i){
            tmp -= memo[j];
            tmp %= mod;
        }
        memo[i] = tmp;
        res += (i * tmp) % mod;
        res %= mod;
    }
    res += mod;
    res %= mod;
    cout << res << endl;
}