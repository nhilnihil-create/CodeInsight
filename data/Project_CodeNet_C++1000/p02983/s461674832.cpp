#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
int main(){
    ll l, r; cin >> l >> r;
    ll ans = 2019;
    bool flg = false;
    for(ll i=l; i<=r; i++){
        for(ll j=i+1; j<=r; j++){
            ll tmp = (i*j) % 2019;
            ans = min(ans, tmp);
            if(tmp==0){
                flg = true; break;
            }
        }
        if(flg) break;
    }
    cout << ans << endl;
    return 0;
}