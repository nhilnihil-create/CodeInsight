#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

int main(){
    ll x,d,k;
    cin >> x >> k >> d;
    if(x<0)x *= -1;
    if(x/d > k){
        cout << x-k*d << endl;
    }
    else{
        k -= x/d;
        ll ans = x - (x/d)*d;
        if(k%2==1) ans = d-ans;
        cout << ans << endl;
    }
    return 0;
}
