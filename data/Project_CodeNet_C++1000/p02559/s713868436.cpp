#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using namespace atcoder;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, q, t, l, r, a;
    cin >> n >> q;
    fenwick_tree<ll> fw(n);
    rep(i, n) {
        cin >> a;
        fw.add(i, a);
    }
    rep(i, q) {
        cin >> t >> l >> r;
        if (t==0) {
            fw.add(l, r);
        } else {
            cout << fw.sum(l, r) << endl;
        }
    }
    return 0;
}