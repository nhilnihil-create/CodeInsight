#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll f(int i) {
    return ((ll)i * (i + 1)) / 2;
}

void swap(int& l, int& r) {
    l = l^r;
    r = l^r;
    l = l^r;
}

int main() {
    int n, l, r;
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += f(i);
    }
    for(int i = 0; i < n - 1; i++) {
        cin >> l >> r;
        if(l > r) swap(l, r);
        ans -= (ll)l * (n - r  + 1);
    }
    cout << ans;
    return 0;
}