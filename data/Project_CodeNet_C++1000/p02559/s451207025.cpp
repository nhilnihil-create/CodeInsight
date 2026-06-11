#include <iostream>
#include <vector>
#include <cmath>

#include <atcoder/dsu>
#include <atcoder/fenwicktree>
#include <cstdio>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
typedef long long ll;

using namespace atcoder;

int main()
{
    ll n, q;
    ll ans = 0;
    scanf("%lld %lld", &n, &q);
    vector <ll> A(n, 0);
    for (int i = 0; i < n; i ++){
        scanf("%lld", &A.at(i));
    }
    fenwick_tree<ll> fw(n);
    FOR(i,0,n) {
        fw.add(i,A[i]);
    }
    FOR(i,0,q) {
        ll t;
        scanf("%lld", &t);
        if (t==0) {
            ll p, x;
            scanf("%lld %lld", &p, &x);  
            fw.add(p, x);
        } else {
            ll l, r;
            scanf("%lld %lld", &l, &r);
            ans = fw.sum(l, r);
            printf("%lld\n", ans);  
        }
    }
    return 0;
}