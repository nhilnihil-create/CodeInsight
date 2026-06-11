#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;



int main() {
    ll l,r; cin >> l >> r;
    ll d = l%2019;
    ll ans = 2020;

    if(r-l > 2019-d) cout << 0;
    else {
        for(ll i = l; i < r; i ++){
            for(ll j = i+1; j <= r; j ++){
                ans = min(ans,((i%2019)*(j%2019))%2019);
            }
        }
        cout << ans;
    }
    return 0;
}









