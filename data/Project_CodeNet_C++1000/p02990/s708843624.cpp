#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);



ll modpow(ll a,ll n){
    ll res = 1;
    while(n > 0){
        if(n&1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll modinv(ll x){
    return modpow(x,mod-2);
}

ll comb(ll n, ll k){
    ll ans1 = 1;
    ll ans2 = 1;
    rep(i,0,k) ans1 = ans1 * (n-i) % mod;
    rep(i,0,k) ans2 = ans2 * (i+1) % mod;
    return ans1*modinv(ans2) % mod;
}


int main(){
    FIN;
    ll n,k; cin >> n >> k;
    for(int i=1;i<=k;i++){
        cout << (comb(n-k+1,i) * comb(k-1,i-1))%mod << endl;
    }
    return 0;
}
