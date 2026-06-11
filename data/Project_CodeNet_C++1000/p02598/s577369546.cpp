#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

int main(){
    ll n,k;
    cin >> n >> k;
    ve<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    ll l = 0, r = a[n-1];
    while(r-l>1){
        ll x = (l+r)/2;
        ll cnt=0;
        rep(i,n){
            cnt += (a[i]+x-1)/x-1;
        }
        if(cnt <= k)r=x;
        else l = x;
    }
    cout << r << endl;
    return 0;
}
