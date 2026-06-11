#include <bits/stdc++.h>
using namespace std;

#define ll long long 

ll gcd(ll a, ll b) {
    return (a ? gcd(b%a, a) : b); 
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b); 
}


int main() {
    ios::sync_with_stdio(0); 

    
    int n, m; 
    cin >> n >> m;
    vector<ll> a(n); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    ll ans = 1; 
    for (auto x : a) ans = lcm(ans, x);

    bool ok = true; 
    for (auto x : a) {
        if (not (  (ans / x) & 1 ) ) ok = false ; 
    }

    if (ok) {
        ans = int((double)m/ans + 0.5); 

    } else 
        ans = 0; 

    cout << ans << "\n"; 

    return 0; 
}

