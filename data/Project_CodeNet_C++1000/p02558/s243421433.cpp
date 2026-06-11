#include <iostream>
#include <vector>
#include <cmath>

#include <atcoder/dsu>
#include <cstdio>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
typedef long long ll;

using namespace atcoder;

int main()
{
    ll n, q;
    ll ans = 0;
    ll cnt = 0;
    scanf("%lld %lld", &n, &q);
    dsu d(n);
    for (ll i = 0; i < q; i++) {
        ll t, u, v;
        scanf("%lld %lld %lld", &t, &u, &v);
        if (t == 0) {
            d.merge(u, v);
        } else {
            if (d.same(u, v)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}