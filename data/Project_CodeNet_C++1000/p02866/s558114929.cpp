#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll MOD = 998244353;
 

ll N, ans=1, tmp=0;
map<ll, ll> M;

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        tmp = max(tmp, a);
        M[a]++;
        if(!i&&a!=0) {
            cout << 0 << endl;
            return 0;
        }
        if(i&&a==0) {
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i=0;i<=tmp;i++) {
        if(i>1) {
            ans *= modpow(M[i-1], M[i], MOD);
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}