#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    ll x = 0;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        x ^= a[i];
    }
    rep(i, n) {
        ll ans = x ^ a[i];
        cout << ans << endl;
    }
    return 0;
}
