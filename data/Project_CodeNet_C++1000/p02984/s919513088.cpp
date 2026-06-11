#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    ll a[n];
    rep(i,n) cin >> a[i];
    ll ans[n];
    ll x1 = 0;
    rep(i,n-1) {
        if (i%2) x1 -= 2 * a[i];
        else x1 += 2 * a[i];
    }
    ans[0] = (x1+2*a[n-1])/2;
    rep(i,n-1) {
        ans[i+1] = 2 * a[i] - ans[i];
    }
    rep(i,n-1) {
        printf("%lld ", ans[i]);
    }
    printf("%lld\n", ans[n-1]);
    return 0;
}
