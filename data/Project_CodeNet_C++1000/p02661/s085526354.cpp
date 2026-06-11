#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(decltype(n) i=0; i<n; ++i)

int main() {
    ll ans=0, N;
    cin >> N;
    vector<ll> a(N), b(N);
    rep(i,N) cin >> a[i] >> b[i];
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    if (N&1) {
        ll m = N/2;
        ans = b[m] - a[m] +1;
    } else {
        ll m2 = N/2;
        ll m1 = m2-1;
        ans = b[m1]+b[m2]-a[m1]-a[m2]+1;
    }
    cout << ans << endl;
}
