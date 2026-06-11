/**
 *    author:  Taichicchi
 *    created: 20.09.2020 18:38:14
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
    int N, Q;

    cin >> N >> Q;

    dsu d(N);

    rep(i, Q) {
        int t, u, v;
        cin >> t >> u >> v;

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