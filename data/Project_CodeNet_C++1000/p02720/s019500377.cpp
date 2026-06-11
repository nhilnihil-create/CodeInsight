#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> c;

void dfs(ll x) {

    c.push_back(x);
    if (12 < to_string(x).size()) {
        return;
    }
    ll xu, xm, xl;
    xu = x % 10 + 1;
    xm = x % 10;
    xl = x % 10 - 1;
    for (ll i = 0; i < 3; i++) {
        if (i == 0) {
            if (9 < xu) continue;
            x *= 10;
            x += xu;
            dfs(x);
            x -= xu;
            x /= 10;
        }
        else if (i == 1) {
            x *= 10;
            x += xm;
            dfs(x);
            x -= xm;
            x /= 10;
        }
        else if (i == 2) {
            if (xl < 0) continue;
            x *= 10;
            x += xl;
            dfs(x);
            x -= xl;
            x /= 10;
        }
    }
    return;
}

int main() {

    ll k; cin >> k;
    for (ll i = 1; i <= 9 ; i++) {
        dfs(i);
    }
    sort(c.begin(), c.end());
    cout << c[k - 1] << endl;
    return 0;
}