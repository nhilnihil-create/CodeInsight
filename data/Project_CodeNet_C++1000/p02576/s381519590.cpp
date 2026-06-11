#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

ll ceil(ll a, ll b) {
    if(a % b) return a/b + 1LL;
    return a/b;
}

void solve() {
    ll n, x, t;
    cin >> n >> x >> t;
    ll ans = ceil(n, x) * t;
    cout << ans << "\n";
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // int t;
    // cin >> t;
    // while(t--)
        solve();
    
    return 0;
}