#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main() {
    ll k, x;
    cin >> k >> x;
    for (ll i = x-k+1; i < x+k-1; i++) {
        cout << i << ' ';
    }
    cout << x+k-1 << endl;
    return 0;
}
