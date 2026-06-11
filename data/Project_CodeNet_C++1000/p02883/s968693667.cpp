#include <bits/stdc++.h>
using ll = long long;
using namespace std;

//#define int long long
//signed main(){
int main (){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    ll n,k;
    cin >> n >> k ;
    vector<ll> a(n),f(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < n; i++) cin >> f[i];

    sort(a.begin(),a.end());
    sort(f.rbegin(),f.rend());

    ll l=-1;
    ll r=1e17;
    while(r-l>1) {
        ll mid=(r+l)/2;
        ll cnt=0;
        for(ll i = 0; i < n; i++) {
            ll ra = mid/f[i];
            if(ra<a[i]) cnt+=(a[i]-ra);
        }
        if(cnt>k) l=mid;
        else r=mid;
    }
    cout << r << "\n";

    return 0;
}