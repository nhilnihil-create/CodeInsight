#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define ve vector
const ll INF = 2e12;
int main(){
    ll n, k;
    cin >> n >> k;
    ve<ll> a(n),f(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.rbegin(), f.rend());
    ll l = -1, r = INF;
    while(r-l>1){
        ll mid = (l+r)/2;
        bool ok = [&]{
            ll s = 0;
            rep(i,n){
                s += max((ll)0,a[i]-mid/f[i]);
            }
            return s <= k;
        }();
        if(ok) r = mid;
        else l = mid;
    }
    cout << r << endl;
    return 0;
}