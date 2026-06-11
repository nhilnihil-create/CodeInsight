#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <atcoder/dsu>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    atcoder::dsu dsu(n);

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;

        if (t == 0) {
            dsu.merge(u, v);
        } else {
            cout << dsu.same(u, v) << '\n';
        }
    }

    return 0;
}