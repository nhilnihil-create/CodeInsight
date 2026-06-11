#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(a) (a).begin(),(a).end()
 
using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
 
const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

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
    ll m, n;
    cin >> m >> n;

    cout << modpow(m, n, MOD) << endl;
}
