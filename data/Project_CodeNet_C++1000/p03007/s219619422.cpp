#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
// #include <bits/stdc++.h>


using namespace std;
typedef long long li;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    li n;
    cin >> n;
    vector<li> xs(n);

    li negs = 0;
    for (int i = 0; i < n; ++i) {
        cin >> xs[i];
        if (xs[i] < 0) {
            negs += 1;
        }
    }

    li to_negate = max(min(negs, n - 1), 1LL);
    sort(xs.begin(), xs.end());

    if (to_negate == n - 1) {
        li acc = xs[to_negate];
        vector<li> lh, rh;
        for (int i = 0; i < n - 1; ++i) {
            lh.push_back(acc);
            rh.push_back(xs[i]);
            acc -= xs[i];
        }
        cout << acc << endl;
        for (int i = 0; i < n - 1; ++i) {
            cout << lh[i] << " " << rh[i] << endl;
        }
    } else {
        li ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i < to_negate) {
                ans -= xs[i];
            } else {
                ans += xs[i];
            }
        }
        cout << ans << endl;
        li neg_group = xs[n - 1];
        for (int i = 0; i < to_negate - 1; ++i) {
            cout << neg_group << " " << xs[i] << endl;
            neg_group -= xs[i];
        }
        li pos_group = xs[to_negate - 1];
        for (int i = to_negate; i < n - 1; ++i) {
            cout << pos_group << " " << xs[i] << endl;
            pos_group -= xs[i];
        }
        cout << neg_group << " " << pos_group << endl;
    }
    return 0;
}
