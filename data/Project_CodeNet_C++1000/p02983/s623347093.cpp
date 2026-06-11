#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll l, r; cin >> l >> r;
    ll m = min(l+4038, r);
    ll x = 1000100010;
    ll res = 2019;
    for(ll i=l; i<=m; ++i){
        for(ll j=i+1; j<=m; ++j){
            ll x = i*j%2019;
            res = min(res, x);
        }
    }
    cout << res << endl;
    return 0;
}