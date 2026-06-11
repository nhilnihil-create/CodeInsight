#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;

const ll mod = 2019;

int main() {
    ll l, r;
    cin >> l >> r;
    
    if(l/mod != r/mod) {
        cout << 0 << endl;
    }
    else {
        ll ans = mod - 1;
        for(ll i = l; i < r; i++) {
            for(ll j = i+1; j <= r; j++) {
                ans = min(ans, i * j % mod);
            }
        }
        cout << ans << endl;
    }
    
    
    
    return 0;
}
