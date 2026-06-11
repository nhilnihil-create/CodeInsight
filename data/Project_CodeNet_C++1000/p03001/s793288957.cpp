#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    ll n, k, x, y;
    ll ans = 0;
    double s;
    cin >> n >> k >> x >> y;
    s = (double)(n*k)*0.5;
    if (x*2 == n && y*2 == k) {
        ans = 1;
    }
    cout << setprecision(10) <<  s << ' ' << ans << endl;
    return 0;
}

