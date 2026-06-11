#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n, m, x; cin >> n >> m >> x;
    vector<ll> c(n);
    vector<vector<ll>> a(n, vector<ll>(m));
    for(ll i=0; i<n; ++i){
        cin >> c[i];
        for(ll j=0; j<m; ++j){cin >> a[i][j];}
    }
    ll res = 10000000;
    for(ll is=0; is<(1<<n); ++is){
        ll cost = 0;
        vector<ll> us(m, 0);
        for(ll i=0; i<n; ++i){
            if(is&(1<<i)){
                cost += c[i];
                for(ll j=0; j<m; ++j){us[j] += a[i][j];}
            }
        }

        for(ll j=0; j<m; ++j){
            if(us[j]<x){break;}
            if(j==m-1){res = min(res, cost);}
        }
    }
    if(res==10000000){cout << -1 << endl;}
    else{cout << res << endl;}
    return 0;
}