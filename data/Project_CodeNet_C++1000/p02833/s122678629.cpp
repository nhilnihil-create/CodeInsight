#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    ll n;
    cin >> n;
    if(n % 2) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> div;
    ll k = 10;
    while(k <= n) {
        div.push_back(k);
        k *= 5;
    }
    ll ans = 0;
    for(ll x : div) {
        ans += n / x;
    }
    cout << ans << endl;
    return 0;
}
