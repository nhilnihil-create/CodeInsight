#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> U(N-1), V(N-1);
    for ( int i = 0; i < N-1; i++ ) {
        cin >> U[i] >> V[i];
        U[i]--, V[i]--;
    }
    ll s1 = N*(N+1)*(N+2)/6;
    ll s2 = 0;
    for ( int i = 0; i < N-1; i++ ) {
        ll u = U[i], v = V[i];
        if ( u > v ) swap(u,v);
        s2 += (u+1) * (N-v);
    }
    ll ans = s1 - s2;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}