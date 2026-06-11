#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int solve(ll n) {
    set<ll> s;
    for (ll t = 1; t * t < n; ++t) 
    if ((n - 1) % t == 0) {
        if (t > 1) s.insert(t);
        if ((n - 1) / t > 1) s.insert((n - 1) / t);
    }

    for (ll t = 1; t * t <= n; ++t) 
    if (n % t == 0) {
        ll v = n;
        while (t > 1 && v % t == 0) v /= t;
        if (v % t == 1) s.insert(t);
        v = n;
        ll d = n / t;
        while (d > 1 && v % d == 0) v /= d;
        if (v % d == 1) s.insert(d);
    }
    return s.size();
}

int brute(ll n) {
    int ans = 0;
    for (ll t = 2; t <= n; ++t) {
        ll v = n;
        while (v % t == 0) v /= t;
        if (v % t == 1) ++ans;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
}