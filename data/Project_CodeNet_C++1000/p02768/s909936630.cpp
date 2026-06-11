#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0;i<(n);i++)
#define REP(i,n) for (ll i=1;i<=(n);i++)
typedef long long ll;

ll inf = 1000000007;

ll mpow(ll a,ll n){
    if(n==0) return 1;
    if(n%2==0){
        ll t = mpow(a,n/2);
        return t*t%inf;
    }
    return a * mpow(a,n-1) % inf;
}

ll combi(ll n, ll r){
    ll ans = 1;
    rep(i,r){
        ans*=(n-i);
        ans%=inf;
    }
    REP(i,r){
        ans*=mpow(i,inf-2);
        ans%=inf;
    }
    return ans;
}


int main() {
    ll n,a,b;
    cin >> n >> a >> b;
    ll ans = mpow(2,n) - 1;
    ans -= combi(n,a);
    if(ans<0) ans+=inf;
    ans -= combi(n,b);
    if(ans<0) ans+=inf;
    cout << ans << endl;
}