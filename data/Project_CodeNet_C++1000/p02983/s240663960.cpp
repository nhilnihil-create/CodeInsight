#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    ll l,r; cin >> l >> r;
    ll dif = r - l;
    ll ans = 2019;
    if(dif > 2018){
        ans = 0;
    }else{
        for(ll i = l; i < r; ++i) for(ll j = i + 1; j <= r; ++j){
            ans = min(ans,((i * j) % 2019));
        }
    }
    cout << ans << '\n';
    return 0; 
}