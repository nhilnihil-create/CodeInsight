#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1LL << 60;

int main() {
    ll n;
    cin >> n;

    ll maxz = -INF, minz = INF;
    ll maxw = -INF, minw = INF;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        ll z = x + y;
        ll w = x - y;
        maxz = max(maxz, z);
        maxw = max(maxw, w);
        minz = min(minz, z);
        minw = min(minw, w);
    }

    cout << max(maxz - minz, maxw - minw) << endl;
}