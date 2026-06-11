#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    ll res = 0;
    ll ma = min(k,a);
    res+=min(k,a);
    a-=ma;
    k-=ma;
    k = max(ll(0),k);
    ll mb = min(k,b);
    k-=mb;
    k = max(ll(0),k);
    ll mc = min(k,c);
    res-=mc;
    k-=mc;
    k = max(ll(0),k);
    cout << res;
    return 0;
}