#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll pot(ll base, ll potencia) {
    ll tot = 1;
    for (int i = 0; i <= potencia - 1; i++) {
        //cout << tot << '\n';
        tot *= base;
    }
    return tot;
}

int main() {
    ll h;
    cin >> h;
    int lastOne = (64 - __builtin_clzll(h));
    //cout << lastOne << '\n';
    ll ans = pot(2, lastOne) - 1;
    cout << ans << '\n';
    return 0;
}