#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const ll LINF = 1LL<<60;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);

    ll kl = x/d;
    if (kl >= k) {
        cout << x-d*k << endl;
        return 0;
    }
    
    k -= kl;

    ll x1 = x - d*kl;
    ll x2 = abs(x1-d);

    if (k%2) cout << x2 << endl;
    else cout << x1 << endl;

    return 0;
}