#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<pair<ll, int>> factorize (ll n) {
    vector<pair<ll, int>> res;
    for (ll i = 2; i*i <= n; i++) {
        if (n%i) continue;
        res.emplace_back(i,0);
        while (n%i == 0) {
            n /= i;
            res.back().second++;
        } 
    }
    if (n != 1) res.emplace_back(n, 1); // 素数の場合
    return res;
}

ll gcd (int x, int y) {
    if (y == 0) return x;
    return gcd(y, x%y);
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    auto f = factorize(g);
    int ans = f.size() + 1;
    cout << ans << endl;
    return 0;
}