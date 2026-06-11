#include <atcoder/fenwicktree>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N, Q;
    cin >> N >> Q;
    atcoder::fenwick_tree<ll> fw(N);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        fw.add(i, a);
    }
    for (int z = 0; z < Q; z++) {
        int t;
        cin >> t;
        if (t == 0) {
            int p;
            ll x;
            cin >> p >> x;
            fw.add(p, x);
        }else {
            int l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << "\n";
        }
    }
}