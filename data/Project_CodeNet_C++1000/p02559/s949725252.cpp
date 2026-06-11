#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const int INF = 100100100;

int main() {
    int n,q; scanf("%d %d", &n, &q);
    fenwick_tree<ll> fw(n);
    rep(i,n) {
        int a; scanf("%d", &a);
        fw.add(i,a);
    }

    rep(i,q) {
        int t; scanf("%d", &t);
        if (!t) {
            int p,x; scanf("%d %d", &p, &x);
            fw.add(p,x);
        } else {
            int l,r; scanf("%d %d", &l, &r);
            printf("%lld\n", fw.sum(l,r));
        }
    }
    return 0;
}