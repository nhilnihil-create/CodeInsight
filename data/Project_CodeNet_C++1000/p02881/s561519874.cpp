#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll n;
    cin >> n;
    ll x = 0, y = 0;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n%i == 0) {
            x = i;
            y = n/i;
        }
    }
    ll ans = x-1 + y-1;
    cout << ans << endl;
    return 0;
}