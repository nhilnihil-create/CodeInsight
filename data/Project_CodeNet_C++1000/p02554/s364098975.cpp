#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

//MODでべき乗が計算できる
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
    ll n;
    cin >> n;

    ll ans = modpow(10, n, MOD);

    ll exp1and9 = modpow(8, n, MOD);
    ll exp1or9 = modpow(9, n, MOD) - exp1and9; 

    ans -= exp1and9 + 2 * exp1or9;
    ans += 10*MOD;
    ans %= MOD;

    cout << ans << endl;
}