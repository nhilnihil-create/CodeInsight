#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P  = pair<int, int>;



int main(){

    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll sum = 0;
    rep(i,n) sum += a[i];
    set<ll> c;
    for (int i = 1; i*i < sum; i++){
        if (sum%i==0){
            c.insert(i);
            c.insert(sum/i);
        }
    }
    ll ans = 1;
    for (ll x: c){
        ll now = 1e18;
        vector<ll> r(n);
        rep(i,n) r[i]=a[i]%x;
        sort(r.begin(),r.end());
        ll ms = 0;
        ll mm = 0;
        rep(i,n) ms += x-r[i];
        rep(i,n){
            ms -= x-r[i];
            mm += r[i];
            now = min(now,max(ms,mm));


        }
        if (now <= k){
            ans = max(ans,x);
        }


    }
    cout << ans << endl;
}