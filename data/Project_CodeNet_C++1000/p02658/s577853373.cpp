#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)

int main() {
    ll ans, n;
    ans = 1;
    cin >> n;
    ll a;
    ll MAX = 1e18;
    bool over = false;
    rep(i, n) {
        cin >> a;

        if (a == 0){
            ans = 0;
            break;
        }
        if (over) continue;
        if (a <= MAX/ans) {
            ans *= a;
        }else {
            ans = -1;
            over = true;
        }
    }
    cout << ans << endl;
    return 0;
}

