#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

// a^n mod を計算する
// O(logn)
ll modpow(ll a, ll n, ll mod=MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    ll ans=0;
    rep(d,61){
        ll c0=0,c1=0;
        rep(i,n){
            if(a[i] & 1LL<<d) c1++;
            else c0++;
        }
        
        ll tmp=(c0*c1)%MOD;
        tmp=(tmp*modpow(2,d))%MOD;
        //cout<<c0<<" "<<c1<<endl;
        ans=(ans+tmp)%MOD;
    }

    cout<<ans<<endl;
}

