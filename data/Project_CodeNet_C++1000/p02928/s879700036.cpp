#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

const ll MOD = 1e9+7;

int main()
{
    ll i,j;
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    ll t1 = 0;
    ll t2 = 0;
    for(i = 0;i < n;++i){
        rep(j,n){
            if(i < j && a.at(i) > a.at(j)) ++t1;
            else if(a.at(i) > a.at(j)) ++t2;
        }
    }
    ll ans = k*(k+1)/2%MOD*t1%MOD + k*(k-1)/2%MOD*t2%MOD;
    cout << ans%MOD << endl;

    return 0;
}