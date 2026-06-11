/**
 *    author:  Taichicchi
 *    created: 20.09.2020 18:50:50
 **/

#include <bits/stdc++.h>

#include <algorithm>
#include <atcoder/all>
#include <iostream>
#include <vector>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main() {
    ll N, Q;

    cin >> N >> Q;

    fenwick_tree<ll> fw(N);

    int a;

    rep(i, N) {
        cin >> a;
        fw.add(i, a);
    }

    rep(i, Q) {
        int q, x, y;
        cin >> q >> x >> y;

        if (q == 0) {
            fw.add(x, y);
        } else {
            cout << fw.sum(x, y) << endl;
        }
    }

    return 0;
}