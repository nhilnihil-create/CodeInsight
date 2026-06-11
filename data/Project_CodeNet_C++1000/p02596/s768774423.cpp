#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

int main(){
    ll k;
    cin >> k;
    if(k%2 == 0 || k%5 == 0){
        cout << -1 << endl;
        return 0;
    }
    ll ans = 1, mod = 7, x=10;
    while(1){
        if(mod % k == 0)break;
        ans++;
        mod += x*7;
        mod %= k;
        x *= 10;
        x %= k;
    }
    cout << ans << endl;
    return 0;
}
