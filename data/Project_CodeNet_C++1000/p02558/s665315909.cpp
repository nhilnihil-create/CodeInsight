#include<bits/stdc++.h>
#include<atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long int;
using lc = complex<double>;

int main(void) {
    constexpr ll MOD = 1e9 + 7;
    constexpr double PI = acos(-1);
    cout << fixed << setprecision(32);
    cin.tie(0); ios::sync_with_stdio(false);

    ll n, q;
    cin >> n >> q;
    dsu d(n);
    while(q--) {
        ll t, a, b;
        cin >> t >> a >> b;
        if(t)
            cout << d.same(a, b) << endl;
        else
            d.merge(a, b);
    }
}