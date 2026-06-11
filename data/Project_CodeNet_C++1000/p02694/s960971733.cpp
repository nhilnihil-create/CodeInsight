#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    ll x; cin >> x;
    ll ans;
    ll money = 100;
    for(ll i=1; i<1e25; i++) {
        money += money/100;
        if(money>=x) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}