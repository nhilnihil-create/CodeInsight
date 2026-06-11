#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;

pair<ll, ll> func(ll x) {
    if (x < 10) {
        return pair<ll, ll>(x, x);
    }

    ll a = x%10, b;
    while (x >= 10)
        x /= 10;
    
    b = x;
    return pair<ll, ll>(b,a);
}

int main() {
    int n;  cin >> n;
    vector<vector<ll> > v(10, vector<ll>(10, 0));
    for (ll i = 1; i <= n; i++) {
        pair<ll, ll> p = func(i);
        v[p.first][p.second]++;
    }

    ll ans = 0;
    for (ll i = 0; i <= 9; i++) {
        for (ll j = 0; j <= 9; j++) 
            ans += v[i][j] * v[j][i];
    }

    cout << ans << endl;

    return 0;
}